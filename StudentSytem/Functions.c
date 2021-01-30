
#ifndef Functions_H_
#define Functions_H_

#include <stdio.h>
#include <conio.h>

#include "DataTypes.h"
#include "header.h"





/* function to return by value */
Student Input_Student(void)
{    
    Student Student_Table;
    u8 add_More;

    while (1)
    {
        
        printf("Please Enter Name of Student: ");
        gets(Student_Table.Student_Name);

        printf("Please enter ID: ");
        scanf("%d",&Student_Table.ID);
        
        printf("Please enter Grade: ");
        scanf("%s",Student_Table.Grade);
        
        printf("Please enter Gender: ");
        scanf(" %c",&Student_Table.Gender);
        
        printf("Please enter Birthday\n");
        printf("Day:");
        scanf("%d",&Student_Table.Birth.Day);
        
        printf("Month:");
        scanf("%d",&Student_Table.Birth.Month);
        
        printf("Year:");
        
        scanf("%d",&Student_Table.Birth.Year);
        printf("Add more student (Y/N): ");
        scanf(" %c",&add_More);
        
        fflush(stdin);

        if (add_More=='Y')
        {
            
        }
        else
        {
            break;
        }
        
    }
    return Student_Table;
    
}

/* function to return by reference using pointer */
void Input_Student_Ptr(Student* Ptr_Student)
{   
    
    u8 add_More;

    while (1)
    {
        printf("Please Enter Name of Student: ");
        gets(Ptr_Student->Student_Name);

        printf("Please enter ID: ");
        scanf("%d",&Ptr_Student->ID);
        
        printf("Please enter Grade: ");
        scanf("%s",Ptr_Student->Grade);
        
        printf("Please enter Gender: ");
        scanf(" %c",&Ptr_Student->Gender);
        
        printf("Please enter Birthday\n");
        printf("Day:");
        scanf("%d",&Ptr_Student->Birth.Day);
        
        printf("Month:");
        scanf("%d",&Ptr_Student->Birth.Month);
        
        printf("Year:");
        scanf("%d",&Ptr_Student->Birth.Year);

        printf("Add more student (Y/N): ");
        scanf(" %c",&add_More);
        fflush(stdin);

        if (add_More=='Y')
        {
            
        }
        else
        {
            break;
        }
        
    }
    
}


/* print all data that take from struct by value */ 
void Display(const Student st)
{
    printf("Name: %s\n",st.Student_Name);
    printf("ID: %d\n",st.ID);
    printf("Grade: %s\n",st.Grade);
    printf("Gender: %c\n",st.Gender);
    printf("Date of Birth: %d/%d/%d\n",st.Birth.Day, st.Birth.Month, st.Birth.Year);
}


/* print all data that take from struct by reference */
void Display_Ptr(const Student* st)
{
    printf("Name: %s\n",st->Student_Name);
    printf("ID: %d\n",st->ID);
    printf("Grade: %s\n",st->Grade);
    printf("Gender: %c\n",st->Gender);
    printf("Date of Birth: %d/%d/%d\n",st->Birth.Day, st->Birth.Month, st->Birth.Year);
}

/* array of struct */
void Input_Student_List(Student* Ptr_List, u8 Size)
{
    u8 i;

    for (i=0; i<Size; i++)
    {
        fflush(stdin);
        printf("Please Enter Name of Student: ");
        gets((Ptr_List+i)->Student_Name);

        printf("Please enter ID: ");
        scanf("%d",&(Ptr_List+i)->ID);
        
        printf("Please enter Grade: ");
        scanf("%s",(Ptr_List+i)->Grade);
        
        printf("Please enter Gender: ");
        scanf(" %c",&(Ptr_List+i)->Gender);
        
        printf("Please enter Birthday\n");
        printf("Day:");
        scanf("%d",&(Ptr_List+i)->Birth.Day);
        
        printf("Month:");
        scanf("%d",&(Ptr_List+i)->Birth.Month);
        
        printf("Year:");
        scanf("%d",&(Ptr_List+i)->Birth.Year);

        // printf("Add more student (Y/N): ");
        // scanf(" %c",&add_More);
    }
}


void Display_List(const Student* st, u8 Size)
{
    printf("---------------------------------\n");
    u8 i;
    for (i=0; i<Size; i++)
    {
        printf("Name: %s\n",(st+i)->Student_Name);
        printf("ID: %d\n",(st+i)->ID);
        printf("Grade: %s\n",(st+i)->Grade);
        printf("Gender: %c\n",(st+i)->Gender);
        printf("Date of Birth: %d/%d/%d\n",(st+i)->Birth.Day, (st+i)->Birth.Month, (st+i)->Birth.Year);
        printf("---------------------------------\n");
    }
}


#endif