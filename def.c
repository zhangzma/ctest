#include <stdio.h>
#include <stdint.h>

#define Mul( a,b) a * b


#define AP_MAX_NAME_SIZE 16
#define AP_NESTED_GROUPS_ENABLED

// a variant of offsetof() to work around C++ restrictions.
// this can only be used when the offset of a variable in a object
// is constant and known at compile time
#define AP_VAROFFSET(type, element) (((uintptr_t)(&((const type *)1)->element))-1)

// find the type of a variable given the class and element
#define AP_CLASSTYPE(class, element) (((const class *) 1)->element.vtype)

// declare a group var_info line
#define AP_GROUPINFO(name, idx, class, element, def) { AP_CLASSTYPE(class, element), idx, name, AP_VAROFFSET(class, element), {def_value : def} }

// declare a nested group entry in a group var_info
#ifdef AP_NESTED_GROUPS_ENABLED
#	define AP_NESTEDGROUPINFO(class, idx) { AP_PARAM_GROUP, idx, "", 0, { group_info : class::var_info } }
#endif

/* typedef unsigned char uint8_t; */
/* typedef unsigned int * uintptr_t; */

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


/** define an int32 parameter */
#define PARAM_DEFINE_INT32(_name, _default)		\
	static const					\
	__attribute__((used, section("__param")))	\
	struct param_info_s __param__##_name = {	\
		#_name,					\
		PARAM_TYPE_INT32,			\
		.val.i = _default			\
	}

/** define a float parameter */
#define PARAM_DEFINE_FLOAT(_name, _default)		\
	static const					\
	__attribute__((used, section("__param")))	\
	struct param_info_s __param__##_name = {	\
		#_name,					\
		PARAM_TYPE_FLOAT,			\
		.val.f = _default			\
	}

/** define a parameter that points to a structure */
#define PARAM_DEFINE_STRUCT(_name, _default)		\
	static const					\
	__attribute__((used, section("__param")))	\
	struct param_info_s __param__##_name = {	\
		#_name,					\
		PARAM_TYPE_STRUCT + sizeof(_default),	\
		.val.p = &_default			\
	}


int main(int argc, char *argv[]) {
{
       int nmul = Mul(2+3, 4+5);
       printf("mul=[%d]\n",nmul);
       struct GroupInfo gi = AP_GROUPINFO("MIN",  0, RC_Channel, radio_min, 1100);

       int a = 3;
       printf("vtype = %d\n", a.vtype);
       
       return 0;
}
