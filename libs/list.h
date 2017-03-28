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
void DATAInsertAtTail(struct data, struct Node*);
void PrintDataList(struct Node*);
#endif //IQ_LIST_H
