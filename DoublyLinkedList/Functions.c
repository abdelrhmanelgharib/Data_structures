/*
 *  Author: El-Gharib
 *  Created On: 30/1/2021
 *  Version: 1
 */

#include "DublyLinkedList.h"

void DisplayDoubleList(DNode_t* Head )
{
    DNode_t* Ptr = Head;

    if (Head == NULL)
    {
        printf("List is an empty\n");
        return;
    }

    printf("THE list is:\n");
    while( Ptr !=NULL )
    {
        printf("\t%5d",Ptr->Data);
        /* asign address of Link node in ptr */
        Ptr = Ptr->Next ;
    }
    printf("\n");
}   /* DisplayDoubleList */


/* Insert new element in first list */
DNode_t* InsertBeginning(DNode_t* Head, u32 Val)
{
    DNode_t* Temp_Ptr;
    
    Temp_Ptr = (DNode_t*)malloc(sizeof(DNode_t));
    
    Temp_Ptr->Data = Val;
    Temp_Ptr->Next = Head;
    Temp_Ptr->Prev = NULL;

    Head->Prev = Temp_Ptr;
    Head = Temp_Ptr;
    
    return Head;
}   /* InsertBeginning */


/* Insert in and empty list */
DNode_t* InsertEmptyList(DNode_t* Head, u32 Val)
{
    DNode_t* Temp_Ptr = NULL;
    /* allocat in heap memory */
    Temp_Ptr = (DNode_t*)malloc(sizeof(DNode_t));

    Temp_Ptr->Data = Val;
    Temp_Ptr->Next = NULL;
    Temp_Ptr->Prev = NULL;

    Head = Temp_Ptr;

    return Head;
}   /* InsertEmptyList */


/* insert new value to the end of list */
void InsertEnd(DNode_t* Head, u32 Val)
{
    DNode_t* Temp_Ptr = NULL;
    DNode_t* Ptr=Head;

    /* allocat in heap memory */
    Temp_Ptr = (DNode_t*)malloc(sizeof(DNode_t));

    /* insert new value to temp */
    Temp_Ptr->Data = Val;
    Temp_Ptr->Next = NULL;

    while (Ptr->Next !=NULL)
    {
        Ptr =Ptr->Next;
    }
    
    Temp_Ptr->Prev = Ptr;
    Ptr->Next=Temp_Ptr;     
}   /* InsertEnd */


void InsertAfter(DNode_t* Head, u32 Val, u32 AfterVal)
{
    DNode_t* Temp_Ptr = NULL;
    DNode_t* Ptr = Head;

    

    while (Ptr !=NULL)
    {
        if (Ptr->Data == AfterVal)
        {
            break;
        }
        else
        {
            Ptr = Ptr->Next;
        }
    }

    if (Ptr ==NULL)
    {
        printf("%d not found in list\n",AfterVal);
    }
    else
    {
        Temp_Ptr = (DNode_t*)malloc(sizeof(DNode_t));
        Temp_Ptr->Data = Val;

        Temp_Ptr->Prev = Ptr;
        Temp_Ptr->Next = Ptr->Next;
        Ptr->Next = Temp_Ptr;
        Ptr->Next->Prev = Temp_Ptr;
    }
    
}   /* InsertAfter */

DNode_t* InsertBefore(DNode_t* Head, u32 Val, u32 BeforeVal)
{
    DNode_t* Temp_Ptr = NULL;
    DNode_t* Ptr = Head;

    if (Head->Data == BeforeVal)
    {
        Head = InsertBeginning(Head, Val);
    }

    while (Ptr->Next !=NULL)
    {
        if (Ptr->Next->Data == BeforeVal)
        {
            break;
        }
        else
        {
            Ptr = Ptr->Next;
        }
    }
    if (Ptr->Next == NULL)
    {
        printf("%d not found in list\n",BeforeVal);
    }
    else
    {
        Temp_Ptr = (DNode_t*)malloc(sizeof(DNode_t));
        Temp_Ptr->Data = Val;

        Temp_Ptr->Next = Ptr->Next;
        Temp_Ptr->Prev = Ptr;

        Ptr->Next = Temp_Ptr;
        Ptr->Next->Prev =Temp_Ptr;

    }
    return Head;
}



DNode_t* CreateList(DNode_t* Head)
{
    s8 Nodes, i, Position, Operation;
    u32 Val, Del_Val;
    u32 After_Before;

    printf("Please Enter Number of Nodes : ");
    scanf("%d",&Nodes);

    if(Nodes > 0)
    {
        printf("please enter first number of nodes: ");
        scanf("%lu",&Val);
        Head = InsertEmptyList(Head, Val);

        for (i=1; i<Nodes; i++)
        {
            printf("enter value of Next node: ");
            scanf("%d",&Val);
            InsertEnd(Head, Val);
        }

        printf("enter a value of a node to insert After: ");
        scanf("%d",&After_Before);


        printf("enter value itself: ");
        scanf("%d",&Val);
        InsertAfter(Head,Val,After_Before);

        printf("enter a value of a node to insert Before: ");
        scanf("%d",&After_Before);

        printf("enter value itself: ");
        scanf("%d",&Val);
        Head = InsertBefore(Head,Val,After_Before);

    }
    return Head;

}