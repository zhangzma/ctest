/* fscanf example. */
#include <stdio.h>

int main(int argc, char *argv[])
{
    char str[80];

    float f;
    FILE *pFile;

    pFile = fopen("myfile.txt", "w+");
    fprintf(pFile, "%f %s", 3.1415, "PI");
    rewind(pFile);
    fscanf(pFile, "%f", &f);
    fscanf(pFile, "%s", str);
    fclose(pFile);
    
    printf("%s:%f\n", str, f);
    return 0;
}

