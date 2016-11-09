
#include <stdio.h>
#include <stdlib.h>


// a variant of offsetof() to work around C++ restrictions.
// this can only be used when the offset of a variable in a object
// is constant and known at compile time
#define AP_VAROFFSET(type, element) (((uintptr_t)(&((const type *)1)->element))-1)

// find the type of a variable given the class and element
#define AP_CLASSTYPE(class, element) ((uint8_t)(((const class *) 1)->element.vtype))

// declare a group var_info line
#define AP_GROUPINFO(name, idx, class, element, def) { AP_CLASSTYPE(class, element), idx, name, AP_VAROFFSET(class, element), {def_value : def} }

// the Info and GroupInfo structures are passed by the main
// program in setup() to give information on how variables are
// named and their location in memory
struct GroupInfo {
    uint8_t type; // AP_PARAM_*
    uint8_t idx;  // identifier within the group
    const char name[AP_MAX_NAME_SIZE+1];
    uintptr_t offset; // offset within the object
    union {
        const struct GroupInfo *group_info;
        const float def_value;
    };
};

int main(int argc, char *argv[])
{
    const struct GroupInfo var_info[] PROGMEM = {
    // @Param: TOTAL
    // @DisplayName: Total mission commands
    // @Description: The number of mission mission items that has been loaded by the ground station. Do not change this manually.
    // @Range: 0 32766
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("TOTAL",  0, AP_Mission, _cmd_total, 0),

    // @Param: RESTART
    // @DisplayName: Mission Restart when entering Auto mode
    // @Description: Controls mission starting point when entering Auto mode (either restart from beginning of mission or resume from last command run)
    // @Values: 0:Resume Mission, 1:Restart Mission
    AP_GROUPINFO("RESTART",  1, AP_Mission, _restart, AP_MISSION_RESTART_DEFAULT),
    // @Param: RAW_SENS
    // @DisplayName: Raw sensor stream rate
    // @Description: Stream rate of RAW_IMU, SCALED_IMU2, SCALED_PRESSURE, and SENSOR_OFFSETS to ground station
    // @Units: Hz
    // @Range: 0 10
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("RAW_SENS", 0, GCS_MAVLINK, streamRates[0],  0),

    // @Param: EXT_STAT
    // @DisplayName: Extended status stream rate to ground station
    // @Description: Stream rate of SYS_STATUS, MEMINFO, MISSION_CURRENT, GPS_RAW_INT, NAV_CONTROLLER_OUTPUT, and LIMITS_STATUS to ground station
    // @Units: Hz
    // @Range: 0 10
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("EXT_STAT", 1, GCS_MAVLINK, streamRates[1],  0)
    }

    
    return 0;
}

