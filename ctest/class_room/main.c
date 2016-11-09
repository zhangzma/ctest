/* main.c */
#include "class_room.h"

void help_info();
void create_class_room(pclassroom phClassRoom);
void modify_class_room(pclassroom phClassRoom);
void delete_class_room(pclassroom phClassRoom);
void sreach_class_room(pclassroom phClassRoom);
void print_info(phClassRoom);

int main(int argc, char *argv[])
{
    bool running_flag = true;
    pclassroom phClassRoom;

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

    return 0;
}

/** 主帮助菜单 */
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
}

void create_class_room(pclassroom phClassRoom)
{
    char name[NAME_LE];

    printf("Please input the class's name: ");
    scanf("%s", name);

    pclassroom pNewClass = (pclassroom)malloc(sizeof(pclassroom));
    memcpy(pNewClass->name, name);

    // 将新的班级添加到链表中头
    if (phClassRoom == NULL)
    {
        phClassRoom = pNewClass;
    }
    else
    {
        pNewClass->_next = phClassRoom;
        phClassRoom = pNewClass;
    }

    printf("The class '%s' has created. ", name);
    printf("Please input class's info.\n");
    modify_class_info(pNewClass);
}

void modify_class_room(phClassRoom);

void delete_class_room(phClassRoom);
void sreach_class_room(phClassRoom);
void print_info(phClassRoom);
