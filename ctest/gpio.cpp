// gpio.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>


#define CONFIG_ARCH_BOARD_PX4FMU_V1 1
#undef  CONFIG_ARCH_BOARD_PX4FMU_V2

void errx(int errcode, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf(fmt, args);
    exit(errcode);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
#ifdef CONFIG_ARCH_BOARD_PX4FMU_V1
		errx(1, "usage: gpio_led {start|stop} [-p <1|2|a1|a2|r1|r2>]\n"
		     "\t-p\tUse pin:\n"
		     "\t\t1\tPX4FMU GPIO_EXT1 (default)\n"
		     "\t\t2\tPX4FMU GPIO_EXT2\n"
		     "\t\ta1\tPX4IO ACC1\n"
		     "\t\ta2\tPX4IO ACC2\n"
		     "\t\tr1\tPX4IO RELAY1\n"
		     "\t\tr2\tPX4IO RELAY2"
		    );
#endif
#ifdef CONFIG_ARCH_BOARD_PX4FMU_V2
		errx(1, "usage: gpio_led {start|stop} [-p <n>]\n"
		     "\t-p <n>\tUse specified AUX OUT pin number (default: 1)"
		    );
#endif
	}
    else
    {
        std::cout << "gpio start." << std::endl;
    }

    return 0;
}

