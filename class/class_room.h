/* class_room.h */

#ifndef _CLASS_ROOM_H_
#define _CLASS_ROOM_H_

#include "student.h"

typedef struct _croom {
    char     name[NAME_LEN];
    pstudent pstu;

    int   stuCount;
    float totalCost;
    float payedCost;
    bool  allPayed;

    struct _croom *next;
}croom, *pcroom;

bool create_a_croom(pcroom* ppcr);
void input_a_croom_info(pcroom pcr);
bool destroy_a_croom(pcroom pcr);
bool destroy_all_croom(pcroom *ppcr);

bool  update_croom_info(pcroom pcr);
float get_payed_rate(pcroom pcr);
void  print_croom_brief(pcroom pcr);
void  print_croom_all_info(pcroom pcr);
void  print_croom_payed_or_unpayed(pcroom pcr, bool payedStatus);

#endif /* _CLASS_ROOM_H_ */
