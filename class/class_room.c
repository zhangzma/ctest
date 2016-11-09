/* class_room.c */

#include "class_room.h"

bool create_a_croom(pcroom* ppcr)
{
    pcroom pcr = (pcroom)malloc(sizeof(croom));

    /* memset(pcr, 0, sizeof(croom)); */
    pcr->pstu = NULL;
    pcr->next = NULL;
    input_a_croom_info(pcr);

    if ((*ppcr) != NULL) {
        pcr->next = *ppcr;
    }
    *ppcr = pcr;
    return true;
}

void input_a_croom_info(pcroom pcr)
{
    printf("Please input class room's name: ");
    scanf("%s", pcr->name);
    while (1) {
        char sel;
        printf("Input a student's info[Y/N]: ");
        setbuf(stdin, NULL);
        scanf("%c", &sel);
        if (sel == 'Y' || sel == 'y') {
            create_a_student(&(pcr->pstu));
        }
        else {
            break;
        }
    }

    update_croom_info(pcr);
}

bool destroy_a_croom(pcroom pcr)
{
    printf("[Debug] Destroy the class room: %s\n", pcr->name);
    destroy_all_student(&(pcr->pstu));
    free(pcr);
    pcr = NULL;
    return true;
}
bool destroy_all_croom(pcroom *ppcr)
{
    while (*ppcr != NULL) {
        pcroom pcr = *ppcr;
        *ppcr = pcr->next;
        destroy_a_croom(pcr);
    }
    
    *ppcr = NULL;
    return true;
}

bool update_croom_info(pcroom pcr)
{
    pstudent pstu = pcr->pstu;

    pcr->stuCount  = 0;
    pcr->totalCost = 0.0f;
    pcr->payedCost = 0.0f;
    pcr->allPayed  = true;

    while (pstu != NULL) {
        pcr->stuCount++;
        pcr->totalCost += get_cost_of_student(pstu->degree);
        if (pstu->payed) {
            pcr->payedCost += get_cost_of_student(pstu->degree);
        }
        else {
            pcr->allPayed = false;
        }
        
        pstu = pstu->next;
    }

    return true;
}

float get_payed_rate(pcroom pcr)
{
    update_croom_info(pcr);

    if (pcr->totalCost == 0.0f) {
        return 0.0;
    }
    else {
        return pcr->payedCost / pcr->totalCost;
    }
}

void  print_croom_brief(pcroom pcr)
{
    printf("\n==============================\n");
    printf("The [%s]'s info:", pcr->name);
    printf("\n==============================\n");

    printf("Student Total: %d\n", pcr->stuCount);
    printf("Total Cost: %f\n", pcr->totalCost);
    printf("Pay Cost: %f\n", pcr->payedCost);
    printf("All payed? %s!\n", pcr->allPayed ? "Yes" : "No");
}
void  print_croom_all_info(pcroom pcr)
{
    print_croom_brief(pcr);
    print_students(pcr->pstu);
    printf("\n\n");
}

void  print_croom_payed_or_unpayed(pcroom pcr, bool payedStatus)
{
    print_croom_brief(pcr);
    printf("All the %s students.\n", payedStatus ? "Payed" : "Unpayed");
    /* printf("--------------------\n"); */

    pstudent pstu = pcr->pstu;
    while (pstu != NULL) {
        if (pstu->payed == payedStatus) {
            print_a_student(pstu);
        }
        pstu = pstu->next;
    }
    printf("\n\n");
}


