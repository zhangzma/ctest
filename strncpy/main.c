

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AP_MAX_NAME_SIZE 16


int main(int argc, char *argv[])
{
    char oldName[AP_MAX_NAME_SIZE] = "RESTART";
    char key[AP_MAX_NAME_SIZE+1];

    strncpy(key, oldName, AP_MAX_NAME_SIZE);
    key[AP_MAX_NAME_SIZE] = 0;
    int len = strlen(key);

    printf("key=%s, len = %d\n", key, len);
    
    return 0;
}
