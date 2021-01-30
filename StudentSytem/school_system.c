#include <stdio.h>
#include <conio.h>

#include "header.h"



void main()
{
    Student st;
    Date Birthday;
    st.Birth = Birthday;
    
    //  Input_Student_Ptr(&st);
    //  Display_Ptr(&st);

    Student Student_List[Length];
    Student* Ptr = Student_List;

    u8 Element;

    printf("Enter size of array: ");
    scanf("%d",&Element);

    Input_Student_List(Ptr, Element);
    Display_List(Ptr, Element);

}   