//
// Created by sagus on 02/02/17.
//

#ifndef IQ_LIST_H
#define IQ_LIST_H
#include "../structures.h"
struct Node *GetNewNode(struct Header);
struct Node *GetHeadNull();
struct Node *InsertAtHead(struct Header, struct Node*);

void InsertAtTail(struct Header, struct Node*);
void PrintList(struct Node*);
void ReversePrintList(struct Node*);

struct Node *InsertDataAtHead(struct data, struct Node*);
struct Node *InsertDataHAtHead(struct data , struct Node *);
void InsertDataAtTail(struct data, struct Node*);
struct Node *InsertDataAtTailDirect(struct data, struct Node *);
void PrintDataList(struct Node*);
struct Node *rewindIQ(struct Node *);
#endif //IQ_LIST_H
