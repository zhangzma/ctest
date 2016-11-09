
#include <iostream>
#include <cstdio>

struct orb_metadata
{
	const char *o_name;
	const size_t o_size;
};

typedef const struct orb_metadata *orb_id_it;
#define ORB_MULTI_MAX_INSTANCES 3
enum ORB_PRIO {
	ORB_PRIO_MIN = 0,
	ORB_PRIO_VERY_LOW = 25,
	ORB_PRIO_LOW = 50,
	ORB_PRIO_DEFAULT = 75,
	ORB_PRIO_HIGH = 100,
	ORB_PRIO_VERY_HIGH = 125,
	ORB_PRIO_MAX = 255
};

#define ORB_ID(_name)		&__orb_##_name

#if defined(__cplusplus)
# define ORB_DECLARE(_name)		extern "C" const struct orb_metadata __orb_##_name __EXPORT
# define ORB_DECLARE_OPTIONAL(_name)	extern "C" const struct orb_metadata __orb_##_name __EXPORT __attribute__((weak))
#else
# define ORB_DECLARE(_name)		extern const struct orb_metadata __orb_##_name __EXPORT
# define ORB_DECLARE_OPTIONAL(_name)	extern const struct orb_metadata __orb_##_name __EXPORT __attribute__((weak))
#endif

ORB_DECLARE(test);

int main(int argc, char const *argv[])
{
	ORB_ID(test);
	return 0;
}