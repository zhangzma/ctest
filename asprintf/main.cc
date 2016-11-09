
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int id = 0;
    char *fname;
    asprintf(&fname, "/fs/microsd/APM/etc/%d.fnc", id);
    printf("%s\n", fname);

    free(fname);
    return 0;
}
