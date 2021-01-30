

#include "header.h"

void Input(void)
{
    u8 Size, i;
    

    printf("please enter number of element in an array: ");
    scanf("%d",&Size);

    /* set size* u16 in memory */
    u16* Ptr =(u16*) malloc(Size*sizeof(u16));     // garbage
    //u16* Ptr = (u16*)calloc(Size,sizeof(u16));      // inilized by 0
    for (i=0; i<Size; i++)
    {
        printf("Enter element number %d: ",i+1);
        scanf("%d",&*(Ptr+i) );
    }
    Bubble_sort(Ptr,Size);
    
    free(Ptr);

}


/* Bubble Sorting Algorithm */
void Bubble_sort(u16* Arr, u8 Size)
{
    u8 i, j;
    s8 Flag = -1;

    /* Outer loop for pass squence */
    for (i=0; i<Size-1; i++)
    {
        Flag=0;
        /* internal loop to get larg element */
        for (j=0; j<Size-1-i; j++)
        {
            if ( *(Arr+j) > *(Arr+j+1) )
            {
                /* swap the larg element to the end of array */
                Swap( &*(Arr+j), &*(Arr+j+1) );
                Flag =1;
            }
        }
        /* check if the array is sorted */
        if (Flag == 0)
        {
            /* Array is sorted, then break */
            printf("Array is sorted\n");
            for (i=0; i<Size; i++)
            {
                printf("element number %d is %d\n",i+1,*(Arr+i));
            }
            return;
        }
    }
    
    printf("Array is sorted \n");
    for (i=0; i<Size; i++)
    {
        printf("element number %d is %d\n",i+1, *(Arr+i));
    }


}

void Swap(u16* Num_One, u16* Num_Two)
{
    u16 Temp;

    Temp = *Num_One;
    *Num_One = *Num_Two;
    *Num_Two = Temp; 
}
