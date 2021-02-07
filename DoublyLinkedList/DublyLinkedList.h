/*
 *  Author: El-Gharib
 *  Created On: 30/1/2021
 *  Version: 1
 */



#ifndef DublyLinkedList_H_
#define DublyLinkedList_H_


#include <stdio.h>
#include <stdlib.h>

#include "DataTypes.h"


typedef struct Node
{
    u32 Data;
    struct Node* Next;
    struct Node* Prev;
}DNode_t;


void DisplayDoubleList(DNode_t* );
DNode_t* InsertBeginning(DNode_t* ,u32 );
DNode_t* InsertEmptyList(DNode_t* , u32);
void InsertEnd(DNode_t* , u32 );

void InsertAfter(DNode_t* , u32 ,u32 );
DNode_t* InsertBefore(DNode_t* , u32 , u32 );

DNode_t* CreateList(DNode_t* );



#endif