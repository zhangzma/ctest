

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


enum Rotation {
	ROTATION_NONE                = 0,
	ROTATION_YAW_45              = 1,
	ROTATION_YAW_90              = 2,
	ROTATION_YAW_135             = 3,
	ROTATION_YAW_180             = 4,
	ROTATION_YAW_225             = 5,
	ROTATION_YAW_270             = 6,
	ROTATION_YAW_315             = 7,
	ROTATION_ROLL_180            = 8,
	ROTATION_ROLL_180_YAW_45     = 9,
	ROTATION_ROLL_180_YAW_90     = 10,
	ROTATION_ROLL_180_YAW_135    = 11,
	ROTATION_PITCH_180           = 12,
	ROTATION_ROLL_180_YAW_225    = 13,
	ROTATION_ROLL_180_YAW_270    = 14,
	ROTATION_ROLL_180_YAW_315    = 15,
	ROTATION_ROLL_90             = 16,
	ROTATION_ROLL_90_YAW_45      = 17,
	ROTATION_ROLL_90_YAW_90      = 18,
	ROTATION_ROLL_90_YAW_135     = 19,
	ROTATION_ROLL_270            = 20,
	ROTATION_ROLL_270_YAW_45     = 21,
	ROTATION_ROLL_270_YAW_90     = 22,
	ROTATION_ROLL_270_YAW_135    = 23,
	ROTATION_PITCH_90            = 24,
	ROTATION_PITCH_270           = 25,
	ROTATION_ROLL_270_YAW_270    = 26,
	ROTATION_ROLL_180_PITCH_270  = 27,
	ROTATION_MAX
};

enum HMC5883_BUS {
	HMC5883_BUS_ALL = 0,
	HMC5883_BUS_I2C_INTERNAL,
	HMC5883_BUS_I2C_EXTERNAL,
	HMC5883_BUS_SPI
};

int main(int argc, char *argv[])
{
    int ch;
    opterr = 0;
    enum HMC5883_BUS busid = HMC5883_BUS_ALL;
	enum Rotation rotation = ROTATION_NONE;
	bool calibrate = false;
	bool temp_compensation = false;

    while ((ch = getopt(argc, argv, "XISR:CT")) != EOF)
    {
        switch(ch)
        {
        case 'R':
			rotation = (enum Rotation)atoi(optarg);
			break;
		case 'I':
			busid = HMC5883_BUS_I2C_INTERNAL;
			break;
		case 'X':
			busid = HMC5883_BUS_I2C_EXTERNAL;
			break;
		case 'S':
			busid = HMC5883_BUS_SPI;
			break;
		case 'C':
			calibrate = true;
			break;
		case 'T':
			temp_compensation = true;
			break;
		default:
            printf("Unuse symobal.\n");
			exit(0);
        }
    }
    
    printf("rotation=%d\n", rotation);
    printf("busid=%d\n", busid);
    printf("calibrate=%d\n", calibrate);
    printf("temp_compensation=%d\n", temp_compensation);

    return 0;
}

