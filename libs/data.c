//
// Created by sagus on 25/02/17.
//
/* Doubly Linked List implementation */
#include "list.h"
#include<stdio.h>

/*
 * Nodos de la Lista
 * data es una estructura con la cabecera de un pulso
 * next y prev apuntan a los nodos vecinos
 */
struct Data {
        struct data muestra;
        struct Data* next;
        struct Data* prev;
};

//Creates a new Data and returns pointer to it.
struct Data *GetNewData(struct data x) {
        struct Data* newData = (struct Data*)malloc(sizeof(struct Data));
        newData->muestra = x;
        newData->prev = NULL;
        newData->next = NULL;
        return newData;
}
/*
 * INICIALIZACIÓN DE UNA LISTA
 * El usuario debe llamar a esta función para obtener la cabecera de una lista.
 * La misma crea una estructura nodo y la devuelve apuntando a NULL
 */
struct Data *DATAGetHeadNull(){
        struct Data *x; // global variable - pointer to head Data.
        return x = NULL;
}

//Inserts a Data at head of doubly linked list
struct Data *InsertDataAtHead(struct data x, struct Data *head) {
        struct Data* newData = GetNewData(x);

        if(head == NULL) {
                head = newData;
                return head;
        }
        head->prev = newData;
        newData->next = head;
        head = newData;
        return head;
}

int DATACountDatas(struct Data *head){
        /*
         * TO BE IMPLEMENTED
         */
}

//Inserts a Data at tail of Doubly linked list
void DATAInsertAtTail(struct data x, struct Data *head) {
        struct Data* temp = head;
        struct Data* newData = GetNewData(x);
        if(head == NULL) {
                head = newData;
                return;
        }
        while(temp->next != NULL) temp = temp->next; // Go To last Data
        temp->next = newData;
        newData->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void DATAPrintList(struct Data *head) {
        struct Data* temp = head;

        printf("V_I+V_Qi | H_I+H_Qi\n");
        while(temp != NULL) {
                printf("%.16lf + %.16f i | %.16lf + %.16f i\n", temp->muestra.v_i, temp->muestra.v_q, temp->muestra.h_i, temp->muestra.h_q);
                temp = temp->next;
        }
}

//Prints all elements in linked list in reverse traversal order.
void DATAReversePrintList(struct Data *head) {
        struct Data* temp = head;
        if(temp == NULL) return; // empty list, exit
        // Going to last Data
        while(temp->next != NULL) {
                temp = temp->next;
        }
        // Traversing backward using prev pointer
        printf("V_I+V_Qi | H_I+H_Qi\n");
        while(temp != NULL) {
                printf("%.16lf + %.16f i | %.16lf + %.16f i\n", temp->muestra.v_i, temp->muestra.v_q, temp->muestra.h_i, temp->muestra.h_q);
                temp = temp->prev;
        }
        printf("\n");
}
