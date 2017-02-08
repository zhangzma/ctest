/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;

void dump(const char *name);
void dump_hex(const uint8_t * buf, int len);
int  get_file_len(FILE *pfile);


int main(int argc, char *argv[])
{
    dump("led.bin");
    return 0;
}

void dump(const char *name)
{
    FILE *fp = fopen(name, "r");

    if (fp != NULL) {
        int len = get_file_len(fp);
        uint8_t *buf = (uint8_t *)malloc(len);
        fread(buf, 1, len, fp);
        printf("#define _IAP_CODE_C_\n");
        printf("#include \"types.h\"\n\n");
        printf("const uint16_t code_led_size = %d;\n", len);
        printf("const uint8_t code_led[code_led_size] = { \n    ");
        dump_hex(buf, len);
        printf("};\n\n");
    } else {
        printf("open file failure: %s.\n", name);
    }

    fclose(fp);
}

int get_file_len(FILE *pfile)
{
    fseek(pfile, 0, SEEK_END);
    int len = ftell(pfile);
    rewind(pfile);

    return len;
}

void dump_hex(const uint8_t * buf, int len)
{
    for (int i  = 0; i < len; i++) {
        printf("0x%02X, ", buf[i]);
        if ((i+1) % 8 == 0) {
            printf("\n    ");
        }
    }
}


