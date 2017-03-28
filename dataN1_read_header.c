
// Created by sagus on 26/01/17.
/* [ header ] = dataN1_read_header( filename, varargin )
 *  DATAN1_READ_HEADER Lee y parsea los datos de Nivel 1
 *  filename: nombre del archivo a leer.
 *  header: encabezado del dato N1.
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

struct Node *dataN1_read_header(char *filename, int n_args, ...){
        int idx;

        struct Node *nodeHeader;
        struct Header h;


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

        fid = fopen(filename, O_RDONLY);
        if(fid==NULL){
                printf("err %d \n", errno);
                return 0;
        }

        /* SAMPLES */
        int m = 1;
        int n = 1;
        int max_channel=MAX_CHANNEL;
        int iq=IQ;
        int sample_size=SAMPLE_SIZE;
        int max_datan1_file=MAX_DATAN1_FILE;

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
                                        if(fseek(fid,2,SEEK_CUR)!=0){
                                                fprintf(stderr, "ERROR: Fseek, Value of errno: %d\n", errno);
                                                exit(EXIT_FAILURE);
                                        }
                                        if(fseek(fid, h.validSamples * max_channel * iq * sample_size, SEEK_CUR)
                                                != 0) {
                                                fprintf(stderr, "ERROR: Fseek, Value of errno: %d\n", errno);
                                                exit(EXIT_FAILURE);
                                        }
                                        m++;
                                        printf("INGRESA AL idx!=m\n");
                                        continue;   /* next loop pof while */
                                }

                                /* APUNTAMIENTO VER */
                                if(fseek(fid, 2, SEEK_CUR)!= 0) {
                                        fprintf(stderr, "ERROR: Fseek, Value of errno: %d\n", errno);
                                        exit(EXIT_FAILURE);
                                }

                                /* Implementation of a doubly linked list to store the N headers */
                                nodeHeader = InsertAtHead(h, nodeHeader);

                                /* APUNTAMIENTO VER */
                                if(fseek(fid, h.validSamples*max_channel*iq*4, SEEK_CUR)!= 0) {
                                        fprintf(stderr, "ERROR: Fseek, Value of errno: %d\n", errno);
                                        exit(EXIT_FAILURE);
                                }
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