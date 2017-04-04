/** \file list.c
 *  \brief Double linked list implementations
 *  \author Agustín Martina (amartina@unc.edu.ar)
 *
 * \todo CountNodes functions: counts the length of a linked list
**/
#include "list.h"
#include<stdio.h>

/** \brief node of IQ data structure
**/
struct Data {
        struct data muestra;
        struct Data* next;
        struct Data* prev;
};

/** \brief node of Header data structure
**/
struct Node {
        struct Header head;
        struct Data *datos;
        struct Node *next;
        struct Node *prev;
};

/** \brief Creates a new node to be inserted into a list of Headers
 * \param[in] x - Header data of a pulse
 * \param[out] newNode - node with the header data
**/
//Creates a new Node and returns pointer to it.
struct Node *GetNewNode(struct Header x) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->head = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}

/** \brief Initialize a linked list with NULL head.
 *
 * The user must call this function to get a head of a new linked list.
 * This functions declare an empty node (pointing null)
 *
 * \param[out] head - head of a new linked list
**/
struct Node *GetHeadNull(){
        struct Node *head; // global variable - pointer to head node.
        return head = NULL;
}


/** \brief Insert a node at the head of a linked list.
 *
 * \param[in]x - A Header structure to be inserted
 * \param[in,out] head - Head of the target linked list
**/
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

/** \brief TODO Length linked list counter
 *
 * \param[in] head - Head of the linked list to be measured
**/
int CountNodes(struct Node *head){
        /*
         * TO BE IMPLEMENTED
         */
}

/** \brief Insert a Node at the tail of doubly linked list
 *
 * @param x[in] - Header structure to be inserted
 * @param head[in,out] - Head of the double linked list target
 */
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


/** \brief Prints all elements of a doubly linked list in a LIFO way
 *
 * @param head[in] - Head of the double linked list target
 */
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

/** \brief Prints all elements of a doubly linked list in a FIFO (reverse) way
 *
 * @param head[in] - Head of the double linked list target
 */
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

/** \brief Creates a new Data node (IQ) and returns pointer to it.
 *
 * @param x[in] - Data IQ structure
 */
struct Data *GetNewDataNode(struct data x) {
        struct Data* newDataNode = (struct Data*)malloc(sizeof(struct Data));
        newDataNode->muestra = x;
        newDataNode->prev = NULL;
        newDataNode->next = NULL;
        return newDataNode;
}

/** \brief Insert a node of IQ data at the head of a Data linked list.
 *
 * \param[in]x - A V structure to be inserted
 * \param[in,out] head - Head of the target linked list
**/
struct Node *InsertDataAtHead(struct data x, struct Node *head) {
        struct Data* newData = GetNewDataNode(x);

        /* si es el primer dato */
        if(head->datos == NULL) {
                head->datos = newData;
                //BORRAR
                //printf("CONTROL: PRIMERO!!! HI=%f, HQ=%f \n", head->datos->muestra.H_I, head->datos->muestra.H_Q);
                return head;
        }

        head->datos->prev = newData;
        newData->next = head->datos;

        head->datos = newData;

        //BORRAR
        //printf("CONTROL: HI=%f, HQ=%f \n", head->datos->muestra.H_I, head->datos->muestra.H_Q);

        return head;
}

/** \brief Insert a node of H IQ data at the head of a Data linked list.
 *
 * \param[in]x - A H structure to be inserted
 * \param[in,out] head - Head of the target linked list
**/
struct Node *InsertDataHAtHead(struct data x, struct Node *head) {

        head->datos->muestra.H_I=x.H_I;
        head->datos->muestra.H_Q=x.H_Q;

        head->datos=head->datos->next;

        return head;
}

/** \brief Insert a node of IQ data at the tail of a Data linked list.
 *
 * \param[in]x - A IQ structure to be inserted
 * \param[in,out] head - Head of the target linked list
**/
void InsertDataAtTail(struct data x, struct Node *head) {
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


/** \brief Insert a node of IQ data at the tail of a Data linked list and returns that header
 *
 * \param[in]x - A IQ structure to be inserted
 * \param[in,out] head - Head of the target linked list
**/
struct Node *InsertDataAtTailDirect(struct data x, struct Node *head) {

        struct Data* newData = GetNewDataNode(x);
        if(head->datos == NULL) {
                head->datos = newData;
                return head;
        }
        while(head->datos->next != NULL) head->datos = head->datos->next; // Go To last Data
        head->datos->prev = head->datos;
        head->datos=newData;

        return head;
}

/** @brief This function go back to the first IQ data
 *
 * We need to return to the first IQ data to fill the data structure with H_I and H_Q
 *
 * @param[in,out] head - Data N1 structure
 */
struct Node *rewindIQ(struct Node *head){
        while(head->datos->prev != NULL) {
                head->datos = head->datos->prev;
        }
        return head;
}

/** @brief Prints all the IQ elements in linked list in forward traversal order
 *
 * @param head - Head of the linked list to be printed
 */
void PrintDataList(struct Node *head) {
        struct Node* temp = head;

       //FILE *fheader;
        //header=fopen("data.csv","w");

        while(temp->datos != NULL) {
                printf("V_I, V_Q | H_I, H_Q\n");
                printf("%.16f, %.16fi| %.16f, %.16fi\n", temp->datos->muestra.V_I, temp->datos->muestra.V_Q, temp->datos->muestra.H_I, temp->datos->muestra.H_Q);

                temp->datos = temp->datos->next;
        }
        //close(fheader);
}