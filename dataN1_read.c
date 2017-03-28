// Created by sagus on 25/01/17.
/*  [samples header time location] = dataN1_read(filename, varargin);
    DATAN1_HEADER Lee y parsea los datos de Nivel 1
    filename: nombre del archivo a leer.
    dn1:  cell array con las muestras de varios pulsos, para ambas polaridades
    header: header de cada pulso de dn1
    dn1: vectores columnas con las muestras complejas o reales segun
    corresponda leidas del archivo 'filename'.
    header: encabezado del dato N1.
*/

#include "dataN1_header.h"
#include "libs/list.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>         /* ISO C variable aruments */

/* DEFINICIONES */
#define MAX_CHANNEL 2;
#define SAMPLE_SIZE 4;      /* bytes */
#define IQ 2;
#define MAX_DATAN1_FILE 10000;

struct Node *dataN1_read(char *filename,int n_args, ...){
        int idx;

        struct Node *nodeHeader;
        struct Header h;
        struct data d = {0,0,0,0};


        va_list ap;
        va_start(ap, n_args);

        FILE *fid;

        /* Inicializamos la lista*/
        nodeHeader=GetHeadNull();

        if (n_args==0){
                /* TO BE IMPLEMENTED: abre un cuadro de diálogo para seleccionar que archivo abrir*/
                printf("TBI: FALTA IMPLEMENTAR APERTURA DE UN ARCHIVO SI NO SE SELECCIONÓ NINGUNO");
        }

        /*lectura de muestras*/
        idx=MAX_DATAN1_FILE;
        if(n_args==2){
                idx = va_arg(ap, int);
        }

        va_end(ap);

        fid = fopen(filename, "r");
        if (fid == NULL){
                printf("FOPEN: err %d \n", errno);
                return 0;
        }

        /* SAMPLES */
        int m = 1;
        int n = 1;
        int max_channel = MAX_CHANNEL;
        int iq = IQ;
        int sample_size = SAMPLE_SIZE;
        int max_datan1_file = MAX_DATAN1_FILE;

        while (!feof(fid)){
                /* Lectura de encabezado */
                h = dataN1_header(fid);

                if(h.version!=9999){    /* if h is not empty CHECK IF THIS WORK */
                        switch(h.version){
                        case 0:
                                printf("Version 0, I have no idea what does this do\n");
                                break;
                        case 2: {
                                if (idx < m) {
                                        if (fseek(fid, h.validSamples*max_channel*iq*sample_size, SEEK_CUR)!= 0) {    // in matlab fseek(fid, h.validSamples*MAX_CHANNEL*IQ*SAMPLE_SIZE, 'cof');
                                                fprintf(stderr, "ERROR: Fseek, Value of errno: %d\n", errno);
                                                exit(EXIT_FAILURE);
                                        }
                                        m++;
                                        printf("INGRESA AL idx!=m\n");
                                        continue;   /* next loop pof while */
                                }

                                /* Implementation of a doubly linked list to store the N headers */
                                printf("ENTRA A onsert head\n");
                                nodeHeader = InsertAtHead(h, nodeHeader);

                                /* Buffered all pulse ray, H and V channels, I and Q data*/
                                float* buffer = malloc(sizeof(float)*(h.validSamples*iq*max_channel));
                                int error=fread(&buffer, sizeof(buffer),1,fid);
                                if (error==0){
                                        perror("Error en lectura\n");
                                }
                                /* ARRAY DE STRUCTS, cuantas */
                                for(int i=0; i<h.validSamples;i++){
                                        d.V_I=0;//(&buffer+sizeof(float)*2*i);//buffer[sizeof(float)*2*i];
                                        /*d.V_Q=buffer[sizeof(float)*(2*i+1)];
                                        d.H_I=((float *)buffer)[sizeof(float)*(h.validSamples+2*i)];
                                        d.H_Q=((float *)buffer)[sizeof(float)*(h.validSamples+2*i+1)];*/
                                        
                                        nodeHeader = InsertDataAtHead(d, nodeHeader);
                                }
                                //size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
                                /*for(ii = 1, i <= max_channel, ii++) {
                                        dn1
                                        { n }(:,ii) = complex(d((2 * (ii - 1) * header(n).validSamples + 1):2:2 * ii
                                                * header(n).validSamples),d(
                                                (2 * (ii - 1) * header(n).validSamples + 2):2:2 * ii
                                                * header(n).validSamples));
                                }*/
                                free(buffer);
                                break;
                        }
                        default:
                                perror("ERROR: Exit by default, no compatible version\n");
                                break;
                        }
                        m++;
                        n++;
                }
        }
        fclose(fid);
        return nodeHeader;

}