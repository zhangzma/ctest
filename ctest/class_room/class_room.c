/* class_room.c */

#define CLASS_ROOM_CPP
#include "class_room.h"

pstu create_a_student()
{
	pstu pStud = (pstu)malloc(sizeof(student));

	// 初始化学生
	pStud->name   = "";
	pStud->degree = E_JUNIOR;
	pStud->cost   = get_cost_of_stu(pStud->degree);
	pStud->payed  = false;
	pStud->next   = NULL;
	return pStud;
}

bool destroy_a_student(pstu pStud)
{
	free(pStud);
	pStud = NULL;
	return true;
}

bool modify_a_student_info(pstu pStud)
{
	printf("Please input the student's name[%s]: ", pStud->name);
	scanf("%s", pStud->name);
	printf("Please input the student's Degree[1.E_JUNIOR;2.E_SCHOLAR;3.E_MASTER]: ");
	scanf("%d", &pStud->degree);
	pStud->cost = get_cost_of_stu(pStud->degree);
	printf("Please input the student's Payed status[0.Unpayed; 1.Payed]: ");
	scanf("%d", &pStud->payed);

	return true;
}

void modify_class_info(pclassroom pNewClass)
{
    printf("%s\n", );
}

/**
 * 根据学生的等级，获取学生的费用
 * @param degree -- 学生等级
 * @return 学生费用
 */
float get_cost_of_stu(int degree)
{
    float cost = 0.0;

    switch (degree)
    {
    case E_JUNIOR:
        cost = g_cost_of_junior;
        break;
    case E_SCHOLAR:
        cost = get_cost_of_scholar(g_cost_of_junior);
        break;
    case E_MASTER:
        cost = get_cost_of_master(g_cost_of_junior);
        break;
    default:
        break;
    }

    return cost;
}


/**
 * 获取本科生的费用
 * @param cost_of_junior -- 专科生费用
 * @return 本科生费用
 */
float get_cost_of_scholar(float cost_of_junior)
{
    return 0.8 * cost_of_junior;
}

/**
 * 获取研究生费用
 * @param cost_of_junior -- 专科生费用
 * @return 研究生费用
 */
float get_cost_of_master(float cost_of_junior)
{
    return 0.7 * get_cost_of_scholar(cost_of_junior);
}
