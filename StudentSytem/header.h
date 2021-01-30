

#ifndef header_H_
#define header_H_

#include "DataTypes.h"

#pragma pack (4)

#define Length 10




typedef struct
{
    u8 Day;
    u8 Month;
    u16 Year;
}Date;


typedef struct
{
    u8 Student_Name[100];
    u32 ID;
    u8 Grade[6]; 
    u8 Gender;
    Date Birth;
}Student;


Student Input_Student(void);
void Display(const Student st);
void Display_Ptr(const Student* st);
void Input_Student_Ptr(Student* st);
void Input_Student_List(Student*, u8);
void Display_List(const Student* st, u8);


#endif