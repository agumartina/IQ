//
// Created by sagus on 25/02/17.
//

#ifndef IQ_DATA_H
#define IQ_DATA_H
#include "../structures.h"
struct Data *GetNewData(struct data);
struct Data *DATAetHeadNull();
struct Data *DATAInsertAtHead(struct data, struct Data*);
void DATAInsertAtTail(struct data, struct Data*);
void DATAPrintList(struct Data*);
void DATAReversePrintList(struct Data*);
#endif //IQ_DATA_H
