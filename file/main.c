#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deal_chars(const char *pbuf, int len);
bool is_header_line(const char* pbuf);
void read_a_point(const char* pbuf, double &x, double &y);
bool read_ploygon_header(const char* pbuf, int &count);

int main(int argc, char *argv[])
{
    FILE *pFile;
    /* pFile = fopen("1.txt", "w"); // 文件打开方式 如果原来有内容也会销毁//向文件写数据 */
    /* fwrite ("hello", //要输入的文字 */
    /*         1,//文字每一项的大小 以为这里是字符型的 就设置为1 如果是汉字就设置为4 */
    /*         5,// 我们也可以直接写5 */
    /*         pFile //我们刚刚获得到的地址 */
    /*         ); */
    /* fclose(pFile); //告诉系统我们文件写完了数据更新，但是我们要要重新打开才能在写 */
    /* fflush(pFile); //数据刷新 数据立即更新 */

    /* 对文件读取操作 */
    pFile     = fopen("1.txt", "r"); //获取文件的指针
    char *pBuf;                     //定义文件指针
    fseek(pFile, 0, SEEK_END);      //把指针移动到文件的结尾 ，获取文件长度

    int   len = ftell(pFile);       //获取文件长度
    pBuf      = new char[len+1];    //定义数组长度
    rewind(pFile);                  //把指针移动到文件开头 因为我们一开始把指针移动到结尾，如果不移动回来 会出错
    fread(pBuf, 1, len, pFile);     //读文件
    pBuf[len] = 0;                  //把读到的文件最后一位 写为0 要不然系统会一直寻找到0后才结束

    printf("len = %d\n", len);
    printf("%s\n", pBuf);

    deal_chars(pBuf, len);

    fclose(pFile); // 关闭文件    
    return 0;
}

void deal_chars(const char *pbuf, int len)
{
    int start(0), end(0);
    char str[30] = {0};

    int count = 0;
    
    for (end = start; end < len; end++) {
        if (pbuf[end] == '\n') {
            strncpy(str, pbuf+start, end-start);
            printf("%s\n", str);
            if (is_comment_line(str)) {
                
            } else if (is_header_line(str)) {
                bool nfz = read_ploygon_header(str, count);
                printf("is %s nfz\n", nfz ? "" : "NOT");
            } else {
                read_a_point(str, x, y);
                
            }

            start = end+1;
        }
    }
}

bool is_comment_line(const char* pbuf)
{
   if (pbuf[0] == 'y' || pbuf[0] == 'Y' ||
       pbuf[0] == 'n' || pbuf[0] == 'N') {
       return true;
   }
   return false;
}

bool is_header_line(const char* pbuf)
{
   if (pbuf[0] == 'y' || pbuf[0] == 'Y' ||
       pbuf[0] == 'n' || pbuf[0] == 'N') {
       return true;
   }
   return false;
}


void read_a_point(const char* pbuf, double &x, double &y)
{
    sscanf(pbuf, "%f,%f", &x, &y);
}

bool read_ploygon_header(const char* pbuf, int &count)
{
    char nfz = '\0';

    sscanf(pbuf, "%c:%d", &nfz, &count);
    return (nfz == 'Y' || nfz == 'y');
}
