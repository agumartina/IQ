//
// Created by sagus on 27/01/17.
//
#ifndef IQ_FUNCTIONS_H
#define IQ_FUNCTIONS_H

#include "structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
        struct Header header;

        struct node *next;
        struct node *prev;
};

//this link always point to first Link
struct node *head = NULL;

//this link always point to last Link
struct node *last = NULL;
struct node *current = NULL;

//is list empty
bool isEmpty() {
        return head == NULL;
}
/*
 * MY NEW LINKED LIST
 */

/*
 * LIST-SEARCH(L, k) finds the first element with key k in list L
 * by a simple linear search, returning a pointer to this element. If no object with
 * key k appears in the list, then the procedure returns NIL .
 */
struct node listSerach(L, k){

        x=L.head;
        while (x != NULL && x.key != k)
                x=x.next;
        return x;
}

/*
 * LIST-INSERT(L, x) Given an element x whose key attribute has already been set,
 * the procedure “splices” x onto the front of the linked list,
 */
void listInsert(L, x){
        x.next = L.head;
        if(L.head!=NULL)
                L.head.prev =x; //L.head.prev denotes the prev attribute of the object that L.head points to
        L.head=x;
        x.prev = NULL;
}

/*
 * LIST-DELETE(L, x) removes an element x from a linked list L
 */
void listDelet(L, x){
        if(x.prev != NULL)
                x.prev.next = x.next;
        else
                L.head = x.next;
        if(x.next != NULL)
                x.next.prev = x.prev;
}



/*
 * HASTA CAAAA MY NEW LINKED LIST
 */

int length() {
        int length = 0;
        struct node *current;

        for(current = head; current != NULL; current = current->next){
                length++;
        }

        return length;
}

//display the list in from first to last
void displayForward() {

        //start from the beginning
        struct node *ptr = head;

        //navigate till the end of the list
        printf("\n[ ");

        while(ptr != NULL) {
                printf("Nº Adquisición: (%u) \n",ptr->header->nroAdquisicion);
                ptr = ptr->next;
        }

        printf(" ]");
}

//display the list from last to first
void displayBackward() {

        //start from the last
        struct Header *ptr = last;

        //navigate till the start of the list
        printf("\n[ ");

        while(ptr != NULL) {

                //print data
                printf("Nº de adquisición: %u\n",ptr->nroAdquisicion);

                //move to next item
                ptr = ptr ->prev;
                printf(" ");
        }

        printf(" ]");
}

//insert link at the first location
void insertFirst(struct Header header) {

        //create a link
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->header=header;
        //link->key = key;
        //link->data = data;

        if(isEmpty()) {
                //make it the last link
                last = link;
        } else {
                //update first prev link
                head->prev = link;
        }

        //point it to old first link
        link->next = head;

        //point first to new first link
        head = link;
}

//insert link at the last location
void insertLast(struct Header header) {

        //create a link
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->header=header;
        //link->key = key;
        //link->data = data;

        if(isEmpty()) {
                //make it the last link
                last = link;
        } else {
                //make link a new last link
                last->next = link;

                //mark old last node as prev of new link
                link->prev = last;
        }

        //point last to new last node
        last = link;
}

//delete first item
struct node* deleteFirst() {

        //save reference to first link
        struct node *tempLink = head;

        //if only one link
        if(head->next == NULL){
                last = NULL;
        } else {
                head->next->prev = NULL;
        }

        head = head->next;
        //return the deleted link
        return tempLink;
}

//delete link at the last location
struct node* deleteLast() {
        //save reference to last link
        struct node *tempLink = last;

        //if only one link
        if(head->next == NULL) {
                head = NULL;
        } else {
                last->prev->next = NULL;
        }

        last = last->prev;

        //return the deleted link
        return tempLink;
}

//delete a link with given key
struct node* delete(uint16_t nroAdquisicion) {

        //start from the first link
        struct node* current = head;
        struct node* previous = NULL;

        //if list is empty
        if(head == NULL) {
                return NULL;
        }

        //navigate through list
        while(current->header->nroAdquisicion != nroAdquisicion) {
                //if it is last node

                if(current->next == NULL) {
                        return NULL;
                } else {
                        //store reference to current link
                        previous = current;

                        //move to next link
                        current = current->next;
                }
        }

        //found a match, update the link
        if(current == head) {
                //change first to point to next link
                head = head->next;
        } else {
                //bypass the current link
                current->prev->next = current->next;
        }

        if(current == last) {
                //change last to point to prev link
                last = current->prev;
        } else {
                current->next->prev = current->prev;
        }

        return current;
}

bool insertAfter(uint16_t nroAdquisicion, struct Header header) {
        //start from the first link
        struct node *current = head;

        //if list is empty
        if(head == NULL) {
                return false;
        }

        //navigate through list
        while(current->header->nroAdquisicion != nroAdquisicion) {

                //if it is last node
                if(current->next == NULL) {
                        return false;
                } else {
                        //move to next link
                        current = current->next;
                }
        }

        //create a link
        struct node *newLink = (struct node*) malloc(sizeof(struct node));
        newLink->header = header;

        if(current == last) {
                newLink->next = NULL;
                last = newLink;
        } else {
                newLink->next = current->next;
                current->next->prev = newLink;
        }

        newLink->prev = current;
        current->next = newLink;
        return true;
}

/*main() {
        insertFirst(1,10);
        insertFirst(2,20);
        insertFirst(3,30);
        insertFirst(4,1);
        insertFirst(5,40);
        insertFirst(6,56);

        printf("\nList (First to Last): ");
        displayForward();

        printf("\n");
        printf("\nList (Last to first): ");
        displayBackward();

        printf("\nList , after deleting first record: ");
        deleteFirst();
        displayForward();

        printf("\nList , after deleting last record: ");
        deleteLast();
        displayForward();

        printf("\nList , insert after key(4) : ");
        insertAfter(4,7, 13);
        displayForward();

        printf("\nList  , after delete key(4) : ");
        delete(4);
        displayForward();
}*/


#endif //IQ_FUNCTIONS_H
