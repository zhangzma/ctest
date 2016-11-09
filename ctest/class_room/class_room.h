/* class_room.h */

#ifndef _CLASS_H_
#define _CLASS_H_

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
/* 定义扩展宏 */
#ifdef CLASS_ROOM_CPP
#define CR_EXT
#else
#define CR_EXT extern
#endif // CLASS_ROOM_CPP

#define NAME_LEN   32           /* 名称长度 */
#define NUM_OF_STU 45           /* 默认每个班级学生数量 */

#define E_JUNIOR  1             /* 专科 */
#define E_SCHOLAR 2             /* 大学 */
#define E_MASTER  3             /* 硕士 */

#define COST_OF_JUNIOR 1000F    /* 专科费用 */

// 定义学生信息
typedef struct _s_stu {
    char  name[NAME_LEN];       /* 学生名称 */
    int   degree;               /* 学生等级：专科、学士、硕士 */
    float cost;                 /* 费用 */
    bool  payed;                // 缴费状态
    struct _s_stu* next;
}student, *pstu;

// 定义班级信息
typedef struct _s_classroom {
	char name[NAME_LEN];        /* 班级名称 */
	int  num;
	stu* pstu;
	float cost;
	float total_cost;
	float rate;
	struct _s_classroom* _next;
}classroom, *pclassroom;


CR_EXT float g_cost_of_junior;

// 学生信息操作接口
pstu create_a_student();
bool destroy_a_student(pstu pStud);
bool modify_a_student_info(pstu pStud);

void modify_class_info(pclassroom pNewClass);

bool find_classroom(const char* name);
void create_classroom(const char* name);
void modify_classroom(const char* name);
void delete_classroom(const char* name);

pstu find_stu(pclassroom pcr, const char* name);
bool add_stu(pclassroom pcr, pstu ps);
bool del_stu(pclassroom pcr, const char* name);
bool mod_stu(pclassroom pcr, const char* name);



float get_cost_of_stu(int degree);
float get_cost_of_scholar(float cost_of_junior);
float get_cost_of_master(float cost_of_junior);

#endif /* _CLASS_H_ */
