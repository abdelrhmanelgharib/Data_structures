/*
 *  Author: El-Gharib
 *  Created On: 28/1/2021
 *  Version: 3
 */






#include "LinkedList.h"



/* Functions */

/* this function to display list  */
void DisplayList(Node_t* Head)
{
    Node_t* Ptr = Head;

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
        Ptr = Ptr->Link;
    }
    printf("\n");
    
}   //DisplayList


/* this function to count number of nodes */
u8 CountNode(Node_t* Head)
{
    Node_t* Ptr = Head;
    u8 Count=0;
    while ( Ptr !=NULL)
    {
        Count++;
        Ptr = Ptr->Link;
    }
    printf("Number of nodes is %d\n",Count);
    return Count;
}   //CountNode


/* this function to search for value */
u16 Search_Val(Node_t* Head, u32 Val)
{
    Node_t* Ptr = Head;
    u8 Position=1;

    /* check to the end of nodes */
    while ( Ptr !=NULL )
    {
        /* check if the stored value equal to val that search for */
        if ( (Ptr->Data) ==Val )
        {
            break;
        }
        Ptr = Ptr->Link;
        Position++;
    }
    /* check if search value is found or not */
    if ( Ptr == NULL )
    {
        printf("%d is not found in the list\n",Val);
        return -1;
    } 
    else
    {
        printf("%d is found at position: %d\n",Val,Position);
        return Position;
    }
}   //Search_Val


/* insert new nodes  */
Node_t* InsertBeginning(Node_t* Head, u32 Vall)
{
    Node_t* Temp = NULL;
    Temp = (Node_t*)malloc(sizeof(Node_t));
    Temp->Data =Vall;
    Temp->Link = Head;
    
    Head = Temp;
    return Head;
}   //InsertBeginning


void InsertBeginning_Ptr(Node_t** Head, u32 Vall)
{
    Node_t* Temp = NULL;
    Temp = (Node_t*)malloc(sizeof(Node_t));
    Temp->Link = *Head;
    Temp->Data = Vall;
    *Head = Temp;
}   //InsertBeginning_Ptr


void InsertEnd(Node_t* Head, u32 Vall )
{
    Node_t* Ptr = Head;

    /* declear new node add in the end */
    Node_t* Temp = NULL;

    /* alocate a new node */
    Temp = (Node_t*)malloc(sizeof(Node_t));
    /* set value in node */
    Temp->Data = Vall;

    /* make pointer point to last node in the list */
    while (Ptr->Link !=NULL)
    {
        Ptr = Ptr->Link; 
    }
    Ptr->Link = Temp;
    /* make last node point to NULL */
    Temp->Link = NULL;
}   //InsertEnd


void InsertAfter(Node_t* Head, u32 Val, u32 AfterVal)
{
    Node_t* Ptr= Head;
    Node_t* Temp = NULL;

    /* make pointer point to NULL */
    while (Ptr !=NULL )     // to access last element
    {
        /* check if the stored value equal to val that search for */
        if (Ptr->Data == AfterVal)
            break;
        else
            Ptr = Ptr->Link;
    }
    /* check if search value is found or not */
    if (Ptr == NULL)
    {
        printf("Invalid value, value not found\n");
    }
    else
    {
        Temp = (Node_t*)malloc(sizeof(Node_t));

        Temp->Data = Val;
        Temp->Link = Ptr->Link ;
        Ptr->Link  = Temp;

    }
}   //InsertAfter


Node_t* InsertBefore(Node_t* Head, u32 Val, u32 BeforeVal)
{
    /* check if list is empty */
    if(Head == NULL)
    {
        printf("Empty List\n");
        return Head;
    }
    /* check if the value to insert before is the first  */
    if (Head->Data == BeforeVal)
    {
        InsertBeginning_Ptr(&Head, Val);
    }
    else
    {
        Node_t* Ptr = Head;
        Node_t* Temp = NULL;

        /* make pointer point to predecessor of a node with particular data */
        while(Ptr->Link !=NULL)     //i don't care about last element (NULL) cauze it before insert
        {
            /* check if the stored value equal to val that search for */
            if (Ptr->Link->Data == BeforeVal)
            {
                break;
            }
            else
            {
                Ptr = Ptr->Link; 
            }
        }
        if (Ptr->Link == NULL)
        {
            printf("Invalid value, value not found\n");
        }
        else
        {
            Temp = (Node_t*)malloc(sizeof(Node_t));
            Temp ->Data = Val;
            Temp->Link = Ptr->Link;
            Ptr->Link  = Temp;
        }
    }
    return Head;
}   //InsertBefore


Node_t* InsertPosition(Node_t* Head, u32 Val, s8 Position)
{
    if (Position == 1)
    {
        InsertBeginning_Ptr(&Head, Val);
        return Head;
    }
    if (Position >0)
    {
        
        s8 Pos;

        Node_t* Ptr = Head;
        Node_t* Temp = NULL;
            
        for(Pos=1; (Pos<Position-1) && (Ptr!=NULL); Pos++)
        {
            Ptr = Ptr->Link;
        }
        if (Ptr == NULL)
        {
            printf("invalid position\n");
        }
        else
        {
            Temp = (Node_t*)malloc(sizeof(Node_t));
            Temp->Data = Val;
            Temp->Link = Ptr->Link;
            Ptr->Link =Temp;
        }
        
    }
    else
    {
        printf("invalid position\n");
    }
    
    
    return Head;
}   //InsertPosition


Node_t* DeleteNode(Node_t* Head, u32 Val)
{
    Node_t* Temp_Ptr = Head;
    Node_t* Del_Ptr;

    /* check if list is an empty */
    if (Head == NULL)
    {
        printf("List is empty\n");
        return Head;
    }
    /* delete first element or only one node in list */
    if(Temp_Ptr->Data == Val)
    {
        Del_Ptr = Temp_Ptr;
        Head = Temp_Ptr->Link;
        free(Del_Ptr);
    }
    /* delete element between or last node  */
    else
    {
        while (Temp_Ptr->Link !=NULL)
        {
            if (Temp_Ptr->Link->Data == Val)
            {
                break;
            }
            else
            {
                Temp_Ptr = Temp_Ptr->Link; 
            }
        }/* check if value search for delete is found or not */
        if (Temp_Ptr->Link == NULL)
        {
            printf("%d is not found in the list\n",Val);
        }
        else
        {
            Del_Ptr = Temp_Ptr->Link;
            Temp_Ptr->Link = Del_Ptr->Link;
            free(Del_Ptr);
        }
    }
    return Head;
}   //DeleteNode


Node_t* ReverseNode(Node_t* Head )
{
    /* check if list is an empty */
    if (Head == NULL)
    {
        printf("List is empty\n");
        return Head;
    }

    Node_t* Ptr = Head;
    Node_t* Prev=NULL, * Next;

    while(Next != NULL)
    {
        Next = Ptr->Link;
        Ptr->Link = Prev;
        Prev = Ptr; 
        Ptr  = Next;
        
    }
    Head = Prev;
    
return Head;
}



/* Function to interact with user */
Node_t* CreateList(Node_t* Head)
{
    s8 Nodes, i, Position, Operation;
    u32 Val, Del_Val;
    u32 After_Before;

    printf("Please Enter Number of Nodes : ");
    scanf("%d",&Nodes);

    if(Nodes > 0)
    {
        printf("please enter first number of nodes: ");
        scanf("%d",&Val);
        InsertBeginning_Ptr(&Head, Val);

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

    
        printf("enter a Position of a node to insert: ");
        scanf("%d",&Position);


        printf("enter value itself: ");
        scanf("%d",&Val);
        Head = InsertPosition(Head,Val,Position);

        printf("enter a value of a node to Delete: ");
        scanf("%d",&Del_Val);

        Head = DeleteNode(Head, Del_Val);


        printf("list is reversed: \n");

        Head = ReverseNode(Head);

    }
    else 
    {
        printf("Number of nodes must be positive\n");
    }
    
    return Head;
    
}   //CreateList