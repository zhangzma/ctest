// main.cc
//
// Note: convert int to enum type.

#include <iostream>
using namespace std;


typedef enum _SYS_DEBUG{
	DEBUG_NON,
	DEBUG_INFO,
	DEBUG_WARN
}SYS_DEBUG;

/* system debug level. */
typedef enum _SYS_DEBUG_LVL{
	SYS_DEBUG_LVL_NON = 0,		/* Do not output any debug info. */
	SYS_DEBUG_LVL_INFO,			/* Output the info+ debug message. */
	SYS_DEBUG_LVL_WARN,			/* Output the warn+ debug message. */
	SYS_DEBUG_LVL_ERROR,		/* Output the error+ debug message. */
	SYS_DEBUG_LVL_CRITICAL,		/* Output the critical+ debug message. */
	SYS_DEBUG_LVL_MAX = 0x7,	/*  */
	SYS_DEBUG_LVL_ALL = 0x8	/* Output ALL the debug message. */
}SYS_DEBUG_LVL;


void dbg_test();
void enum_test();

int main(int argc, char *argv[])
{
    enum_test();
    
    return 0;
}


void dbg_init(SYS_DEBUG_LVL level)
{
    std::cout << level << std::endl;
}

bool dbg_need_output(uint32_t curr, uint32_t limit)
{
	if (curr == SYS_DEBUG_LVL_NON) {
		return 0;
	}

	if (curr & SYS_DEBUG_LVL_ALL) {
		return true;
	} else {
		return (limit >= curr);
	}
}

bool dbg_out_info(uint32_t curr)
{
	return dbg_need_output(curr, SYS_DEBUG_LVL_INFO);
}

bool dbg_out_warn(uint32_t curr)
{
	return dbg_need_output(curr, SYS_DEBUG_LVL_WARN);
}

bool dbg_out_error(uint32_t curr)
{
	return dbg_need_output(curr, SYS_DEBUG_LVL_ERROR);
}

bool dbg_out_critical(uint32_t curr)
{
	return dbg_need_output(curr, SYS_DEBUG_LVL_CRITICAL);
}

void dbg_test()
{
    int ival = 0;

    SYS_DEBUG debug = DEBUG_WARN;
    uint16_t  is    = debug;


	for (int i = 0; i < DEBUG_WARN+2; i++) {
		debug = (SYS_DEBUG)ival++;
		switch (debug) {
		case DEBUG_NON:
		case DEBUG_INFO:
		case DEBUG_WARN:
			std::cout << "Yes" << std::endl;
			break;
		default:
			std::cout << "No" << std::endl;
			break;
		}
	}

	int level = SYS_DEBUG_LVL_ALL;
	// std::cout << "Input the debug level: " << std::endl;
	// std::cin >> level;

	if (dbg_out_critical(level)) {
		std::cout << "c" << std::endl;
	}

	for (level = 0; level <= SYS_DEBUG_LVL_ALL ; level++) {
		std::cout << "\n\n===============================" << std::endl;
		std::cout << level << std::endl;
		if (dbg_out_info(level)) {
			std::cout << "info" << std::endl;
		}

		if (dbg_out_warn(level)) {
			std::cout << "warn" << std::endl;
		}

		if (dbg_out_error(level)) {
			std::cout << "level" << std::endl;
		}

		if (dbg_out_critical(level)) {
			std::cout << "critical" << std::endl;
		}
	}

    std::cout << "is = " << is << std::endl;
}

void enum_test()
{
    dbg_init((SYS_DEBUG_LVL)(SYS_DEBUG_LVL_NON | SYS_DEBUG_LVL_INFO));
}
