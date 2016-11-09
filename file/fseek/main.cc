/* fseek example */
#include <stdio.h>
#include <string.h>

FILE* pfile;
int   FILE_LEN;
int get_file_len(FILE *pfile);
int read_line(FILE *pfile, char *buf, int count, int offset);
char* read_line2(char *str, int num, FILE *stream);
bool is_comment_line(const char* pbuf);
int min(int v1, int v2);

int main ()
{
    char buf[200];
    pfile = fopen("myfile.txt", "r");
    

    if (pfile != NULL) {
        while (read_line2(buf, sizeof(buf)-1, pfile) != 0) {
            char *pc = buf; 
            printf("str = %d, %s", sizeof(pc), buf);
        }
    }

    fclose(pfile);

    return 0;






    // fputs("This is an apple.", pFile);
    // fseek(pFile, 9 , SEEK_SET);
    // fputs(" sam", pFile);
    // fclose(pFile);
    FILE_LEN = get_file_len(pfile);

    printf("len = %d\n", FILE_LEN);
    int len = 0;
    // int len = read_line(pfile, buf, 199, 0);
    read_line2(buf, 200, pfile);
    printf("len = %d, buf = %s\n", len, buf);
    read_line2(buf, 200, pfile);
    // len = read_line(pfile, buf, 199, 0);
    printf("len = %d, buf = %s\n", len, buf);

    len = read_line(pfile, buf, 199, 0);
    // read_line(buf, 200, pfile);
    printf("str = %s\n", buf);
    
    fclose(pfile);
    
    return 0;
}

int min(int v1, int v2)
{
    return v1 > v2 ? v2 : v1;
}

int get_file_len(FILE *pfile)
{
    fseek(pfile, 0, SEEK_END);
    int len = ftell(pfile);
    rewind(pfile);

    return len;
}

int read_line(FILE *pfile, char *buf, int count, int offset)
{
    int len = FILE_LEN - offset;
    len = min(count, len);
    fread(buf, 1, len, pfile);
    
    for (int i = 0; i < len; i++) {
        if (buf[i] == '\n') {
            offset += i+1;
            fseek(pfile, offset, SEEK_SET);
            buf[i+1] = '\0';
            len = i+1;
        }
    }
    
    return len;
}

char* read_line2(char *str, int num, FILE *stream)
{
    memset(str, num , '\0');
    return fgets(str, num, stream);
}

bool is_comment_line(const char* pbuf)
{
   if (pbuf[0] == 'y' || pbuf[0] == 'Y' ||
       pbuf[0] == 'n' || pbuf[0] == 'N') {
       return true;
   }
   return false;
}
