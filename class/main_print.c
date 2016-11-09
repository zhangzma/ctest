/* main_print.c */


#include "main.h"

char print_submenu()
{
    char sel;
    printf("==========5. Print Menu==========\n");
    printf("     1. Print All class room info.\n");
    printf("     2. Print >= 80%.\n");
    printf("     3. Print < 80%.\n");
    printf("     4. Print all Payed.\n");
    printf("     5. Print all Unpayed.\n");
    printf("     0 or other. Back the up menu.\n ");
    setbuf(stdin, NULL);

    return sel;
}

void print_all_croom_info(pcroom pcr)
{
    printf("\n------------------------------\n");
    printf("All class room's info.\n");
    printf("------------------------------\n");
    
    while (pcr != NULL) {
        print_croom_all_info(pcr);
        pcr = pcr->next;
    }
}

void print_croom_info_rate_between(pcroom pcr, float min, float max)
{
    printf("\n------------------------------\n");
    printf("All class room info which rate: %f%%~%f%%.\n", min/100.0, max/100.0);
    printf("------------------------------\n");
    
    while (pcr != NULL) {
        update_croom_info(pcr);
        float rate = pcr->totalCost == 0 ? 0 :
            pcr->payedCost / pcr->totalCost;
        if (rate >= min && rate <= max) {
            print_all_croom_info(pcr);
        }

        pcr = pcr->next;
    }
}

void print_croom_info_paystatus(pcroom pcr, bool payedStatus)
{
    printf("\n------------------------------\n");
    printf("All the student with %s\n", payedStatus ? "PAYED" : "UNPAYED");
    printf("------------------------------\n");
    
    while (pcr != NULL) {
        print_croom_payed_or_unpayed(pcr, payedStatus)
        pcr = pcr->next;
    }
}


void print_info(pcroom pcr)
{
    bool running = true;
    do
    {
        char sel = print_submenu();
        switch (sel) {
        case '1':
            print_all_croom_info(pcr);
            break;
        case '2':
            print_croom_info_rate_between(pcr, 80, 100);
            break;
        case '3':
            print_croom_info_rate_between(pcr, 0, 80);
            break;
        case '4':
            print_croom_info_paystatus(pscr, true);
            break;
        case '5':
            print_croom_info_paystatus(pscr, false);
            break;
        case '0':
        default:
            running = false;
            break;
        }        
    } while (runing);
}
