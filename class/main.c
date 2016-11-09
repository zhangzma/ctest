// main test

#include <stdio.h>
#include <stdlib.h>
#include "class_room.h"

void help_info();


int main(int argc, char *argv[]) 
{
    /* init the cost. */
    g_cost_of_jnr = 100.0f;

    bool running_flag = true;
    pcroom phClassRoom;
    

    help_info();
    do
    {
        char menu = 0;
        scanf("%c", &menu);

        switch (menu) {
            /* 打印帮助信息 */
        case '0':
        case 'i':
            help_info();
            break;

        // 创建一个班级
        case '1':
        case 'c':
            create_class_room(phClassRoom);
            break;

        // 修改一个班级信息
        case '2':
        case 'm':
            modify_class_room(phClassRoom);

            break;
        // 删除一个班级信息
        case '3':
        case 'd':
            delete_class_room(phClassRoom);
            break;
        // 查找班级或学生信息
        case '4':
        case 's':
            sreach_class_room(phClassRoom);
            break;

        // 打印班级信息
        case '5':
        case 'p':
            print_info(phClassRoom);
            break;

        /* 退出系统 */
        case '6':
        case 'q':
            running_flag = false;
            printf("CMS is Exitting.\n");
            break;

        default:
            printf("Cannot support commander.\n");
            break;
        }
    } while (running_flag);

    /* Test student. */
    /* pstudent pheader = NULL; */
    /* create_a_student(&pheader); */
    /* create_a_student(&pheader); */
    /* print_students(pheader); */
    /* /\* destroy_a_student(pheader); *\/ */
    /* destroy_all_student(&pheader); */

    /* Test class room. */
    /* pcroom pRoomHeader = NULL; */
    /* create_a_croom(&pRoomHeader); */
    /* print_croom_all_info(pRoomHeader); */
    /* print_croom_payed_or_unpayed(pRoomHeader, true); */
    /* print_croom_payed_or_unpayed(pRoomHeader, false); */
    /* destroy_all_croom(&pRoomHeader); */
    
	return 0;
}

/** Main Menu */
void help_info()
{
    printf("\nCMS (Cost Management System) Ver 1.00\n");
    printf("=============== Menu ===============\n");
    printf("     0. Print this help info.\n ");
    printf("     1. Create a class room.\n");
    printf("     2. Modify a class's info.\n");
    printf("     3. Delete a class.\n");
    printf("     4. Search Unpaying student.\n");
    printf("     5. Print class's info.\n");
    printf("     6. Exit this System.\n");
    printf("Please Select the menu: ");
    setbuf(stdin, NULL);
}
