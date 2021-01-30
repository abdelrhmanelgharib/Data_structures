#include <stdio.h>
#include "DataTypes.h"



void main()
{
    s32 Address;
    s8* Ptr;
    
    Address = 0x11223344;
    Ptr = (s8*)&Address;

    if (*Ptr == 0x44)
    {
        printf("little-endian\n");
    }
    else if (*Ptr == 0x11)
    {
        printf("big-endian\n");
    }


    int int1 = 1036;
    int int2 =  8;

    int* int_Ptr1 = &int1;
    int* int_Ptr2 = &int2;

    printf("%p\n",int_Ptr1);
    printf("%p\n",int_Ptr2);

    *int_Ptr1 = *int_Ptr2;
    printf("%d",*int_Ptr1);

    

    
    
    

}