/*
 *  Author: El-Gharib
 *  Created On: 28/1/2021
 *  Version: 3
 */


#ifndef LinkedList_H_
#define LinkedList_H_


#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"


typedef struct Node
{
    u16 Data;
    struct Node* Link;
}Node_t;


/* Functions Prototypes */

void DisplayList(Node_t* );
u8 CountNode(Node_t* );
u16 Search_Val(Node_t* , u32 );

Node_t* InsertBeginning(Node_t* , u32 );
void InsertBeginning_Ptr(Node_t** , u32 );
void InsertEnd(Node_t* , u32 );


void InsertAfter(Node_t* , u32 , u32 );
Node_t* InsertBefore(Node_t* , u32 , u32 );
Node_t* InsertPosition(Node_t* , u32 , s8 );

Node_t* DeleteNode(Node_t* , u32 );

Node_t* ReverseNode(Node_t* );

Node_t* CreateList(Node_t* );



#endif