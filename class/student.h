// student.h 
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "typedef.h"

STU_EXT float g_cost_of_jnr;

typedef struct _student
{
    char  name[NAME_LEN];
    int   degree;
    float cost;
    bool  payed;

    struct _student *next;
}student, *pstudent;


bool create_a_student(pstudent* ppstu);
bool destroy_a_student(pstudent pstu);
void update_a_student_info(pstudent pstu);
bool destroy_all_student(pstudent *ppheader);

void print_students(pstudent pHeader);
void print_a_student(pstudent pstu);


float get_cost_of_student(int degree);
float get_cost_of_sch();
float get_cost_of_master();


#endif /* _STUDENT_H_ */
