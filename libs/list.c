//
// Created by sagus on 02/02/17.
//
/* Doubly Linked List implementation */
#include "list.h"

#include<stdio.h>


struct Data {
        struct data muestra;
        struct Data* next;
        struct Data* prev;
};

/*
 * Nodos de la Lista
 * header es una estructura con la cabecera de un pulso
 * next y prev apuntan a los nodos vecinos
 */
struct Node {
        struct Header head;
        struct Data *datos;
        struct Node *next;
        struct Node *prev;
};

//Creates a new Node and returns pointer to it.
struct Node *GetNewNode(struct Header x) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->head = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}
/*
 * INICIALIZACIÓN DE UNA LISTA
 * El usuario debe llamar a esta función para obtener la cabecera de una lista.
 * La misma crea una estructura nodo y la devuelve apuntando a NULL
 */
struct Node *GetHeadNull(){
        struct Node *head; // global variable - pointer to head node.
        return head = NULL;
}

//Inserts a Node at head of doubly linked list
struct Node *InsertAtHead(struct Header x, struct Node *head) {
        struct Node* newNode = GetNewNode(x);

        if(head == NULL) {
                head = newNode;
                head->datos=NULL;

                //BORRAR
                printf("AAAAAACONTROL: primer insert:D INSERT_AT HEAD: %u\n", head->head.validSamples);
                return head;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        head->datos=NULL;

        //BORRAR
        printf("AAAAAACONTROL: INSERT_AT HEAD: %u\n", head->head.validSamples);

        return head;
}

int CountNodes(struct Node *head){
        /*
         * TO BE IMPLEMENTED
         */
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(struct Header x, struct Node *head) {
        struct Node* temp = head;
        struct Node* newNode = GetNewNode(x);
        if(head == NULL) {
                head = newNode;
                head->datos=NULL;
                return;
        }
        while(temp->next != NULL) temp = temp->next; // Go To last Node
        temp->next = newNode;
        newNode->prev = temp;
        newNode->datos=NULL;
}

//Prints all the elements in linked list in forward traversal order
void PrintList(struct Node *head) {
        struct Node* temp = head;
        FILE *fheader;
        fheader=fopen("header.csv","w");
        printf("Version, drxVersion, initCW, azimuth, elevation, idVolumen, idBarrido, idConjunto, idGrupo, idPulso. iniBarrido, finBarrido, finGrupo, inhibido, validSamples, nroAdquisicion, nroSecuencia, timeval_h, timeval_l\n");
        while(temp != NULL) {
                printf("%u, %u, %.19lf, %.11f, %.11f, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %lu, %lu\n", temp->head.version,
                        temp->head.drxVersion, temp->head.initCW, temp->head.azimuth, temp->head.elevation, temp->head.idVolumen,
                        temp->head.idBarrido, temp->head.idConjunto, temp->head.idGrupo, temp->head.idPulso, temp->head.iniBarrido,
                        temp->head.finBarrido, temp->head.finGrupo, temp->head.inhibido, temp->head.validSamples, temp->head.nroAdquisicion,
                        temp->head.nroSecuencia, temp->head.timeval_h, temp->head.timeval_l);
                temp = temp->next;
        }
        fclose(fheader);
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrintList(struct Node *head) {
        struct Node* temp = head;
        if(temp == NULL) return; // empty list, exit
        // Going to last Node
        while(temp->next != NULL) {
                temp = temp->next;
        }
        // Traversing backward using prev pointer
        printf("Version, drxVersion, initCW, azimuth, elevation, idVolumen, idBarrido, idConjunto, idGrupo, idPulso. iniBarrido, finBarrido, finGrupo, inhibido, validSamples, nroAdquisicion, nroSecuencia, timeval_h, timeval_l\n");
        while(temp != NULL) {
                printf("inside the wile \n");
                printf("%u, %u, %.19lf, %.11f, %.11f, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %lu, %lu\n", temp->head.version,
                        temp->head.drxVersion, temp->head.initCW, temp->head.azimuth, temp->head.elevation, temp->head.idVolumen,
                        temp->head.idBarrido, temp->head.idConjunto, temp->head.idGrupo, temp->head.idPulso, temp->head.iniBarrido,
                        temp->head.finBarrido, temp->head.finGrupo, temp->head.inhibido, temp->head.validSamples, temp->head.nroAdquisicion,
                        temp->head.nroSecuencia, temp->head.timeval_h, temp->head.timeval_l);
                temp = temp->prev;
        }
        printf("\n");
}

/*
 * Funciones de la lista de datos
 */
//Creates a new Data and returns pointer to it.

struct Data *GetNewDataNode(struct data x) {
        struct Data* newDataNode = (struct Data*)malloc(sizeof(struct Data));
        newDataNode->muestra = x;
        newDataNode->prev = NULL;
        newDataNode->next = NULL;
        return newDataNode;
}

//Inserts a Data at head of doubly linked list
struct Node *InsertDataAtHead(struct data x, struct Node *head) {
        struct Data* newData = GetNewDataNode(x);

        /* si es el primer dato */
        if(head->datos == NULL) {
                head->datos = newData;
                //BORRAR
                printf("CONTROL: PRIMERO!!! HI=%f, HQ=%f \n", head->datos->muestra.H_I, head->datos->muestra.H_Q);
                return head;
        }

        head->datos->prev = newData;
        newData->next = head->datos;

        head->datos = newData;

        //BORRAR
        printf("CONTROL: HI=%f, HQ=%f \n", head->datos->muestra.H_I, head->datos->muestra.H_Q);

        return head;
}

//Inserts a Data at tail of Doubly linked list
void DATAInsertAtTail(struct data x, struct Node *head) {
        struct Node* temp = head;
        struct Data* newData = GetNewDataNode(x);
        if(head->datos == NULL) {
                head->datos = newData;
                return;
        }
        while(temp->datos->next != NULL) temp->datos = temp->datos->next; // Go To last Data
        temp->datos->next = newData;
        newData->prev = temp->datos;
}

//Prints all the elements in linked list in forward traversal order
void PrintDataList(struct Node *head) {
        struct Node* temp = head;
        int cont=0;
       //FILE *fheader;
        //header=fopen("data.csv","w");

        while(temp != NULL) {

            if(cont==0) {
                        printf("V_I, V_Q | H_I, H_Q\n");

                        printf("%.16f, %.16fi| %.16f, %.16fi\n", temp->datos->muestra.V_I, temp->datos->muestra.V_Q, temp->datos->muestra.H_I, temp->datos->muestra.H_Q);
            }
                temp = temp->next;
                cont++;
        }
        //close(fheader);
}