/* student.c */
#define STUDENT_CPP
#include "student.h"

bool create_a_student(pstudent* pheader)
{
    pstudent pstu = (pstudent)malloc(sizeof(student));
    pstu->next = NULL;
    update_a_student_info(pstu);
    
    if ((*pheader) != NULL) {
        pstu->next = *pheader;
    }
    *pheader = pstu;

    return true;
}
    
bool destroy_a_student(pstudent pstu)
{
    printf("[Debug] Destroy the student: %s\n", pstu->name);
    free(pstu);
    pstu = NULL;
    return true;
}

bool destroy_all_student(pstudent *ppheader)
{
    while (*ppheader != NULL) {
        pstudent pstu = *ppheader;
        *ppheader = (*ppheader)->next;
        destroy_a_student(pstu);
    }
}

void update_a_student_info(pstudent pstu)
{
    printf("Please input student's name: ");
    scanf("%s", pstu->name);
    printf("Please input student's degree [1.JNR;2.SCH;3.MST]: ");
    scanf("%d", &pstu->degree);
    pstu->cost = get_cost_of_student(pstu->degree);

    char payed;
    printf("Payed? or not.[Y/N]: ");
    setbuf(stdin, NULL);
    scanf("%c", &payed);
    pstu->payed = (payed == 'Y' || payed == 'y') ?
        1 : 0;
}

void print_students(pstudent pHeader)
{
    printf("\n--------------------\n");
    printf("Print ALL students info.");
    pstudent pstu = pHeader;
    while (pstu != NULL) {
        print_a_student(pstu);
        pstu = pstu->next;
    }
}

void print_a_student(pstudent pstu)
{
    if (pstu == NULL) {
        return ;        
    }

    printf("\n--------------------\n");
    printf("Name: %s\n", pstu->name);
    printf("Degree[1.JNR;2.SCH;3.MST]: %d\n", pstu->degree);
    printf("Cost: %f\n" , pstu->cost);
    printf("Payed: %s\n", pstu->payed ? "Yes" : "No");    
}

float get_cost_of_student(int degree)
{
    float cost = 0.0f;
    switch (degree) {
    case E_JNR:
        cost = g_cost_of_jnr;
        break;
    case E_SCH:
        cost = get_cost_of_sch();
        break;
    case E_MST:
        cost = get_cost_of_master();
        break;
    default:
        break;
    }

    return cost;
}

float get_cost_of_sch()
{
    return (0.8 * g_cost_of_jnr);
}

float get_cost_of_master()
{
    return (0.7 * get_cost_of_sch());
}
