// 
#include <stdio.h>
#include <string.h>

#define MaxSize 20

struct guest_info{
    char name[8];
    int  sum;
    char time[10];
    int  number;
}GuestList[MaxSize];

void Insert(int *);
void Search(int);
void Update(int);
void Save(int count);
void Delete(int *);
void Show(int);

int main()
{
    int i;
    int count = 0;
    do
    {
        printf("\n");
        printf("1--插入(Insert)\n");
        printf("2--查询(Search)\n");
        printf("3--修改(Update)\n");
        printf("4--保存(Save)\n");
        printf("5--删除(Delete)\n");
        printf("6--显示(Show)\n");
        printf("7--退出(Exit)\n");
        scanf("%d",&i);

        switch(i)
        {
        case 1:Insert(&count);
            break;
        case 2:Search(count);
            break;
        case 3:Update(count);
            break;  
        case 4:Save(count);
            break;  
        case 5:Delete(&count);
            break;
        case 6:Show(count);
            break;
        case 7:break;
        default:printf("错误！请重选");break;
        }
    } while( i != 7);
    
    return 0;
}

void Insert(int *count)
{
    int i, in_number;
    if (*count==MaxSize) {
        printf("Over!!!");return;
    }
    
    printf("number：");
    scanf("%d",&in_number);
    for (i=0;i<*count;i++) {
        if (GuestList[i].number==in_number) {
            printf("已有相同号码：");return;
        }
    }
    
    GuestList[i].number=in_number;
    printf("name：");
    scanf("%s", &GuestList[i].name);
    printf("sum：");
    scanf("%d",&GuestList[i].sum);
    printf("time：");
    scanf("%s", &GuestList[i].time);
    (*count)++;  
}

// 求这个函数，保存插入的数据到d盘txt文件中
/**
 * 将订餐信息保存到硬盘中。保存文件的位置为“D:\\order.txt”，格式如下
 * "number:name:sum:time"
 * @param count -- 订餐信息的数量
 */
void Save(int count)
{
    /* 打开文件 */
    FILE *fp;
    fp = fopen("D:\\order.txt", "w");

    /* 保存 */
    for (int i=0; i<count; i++) {
        fprintf(fp, "%d:%s:%d:%s\n",
                GuestList[i].number,
                GuestList[i].name,
                GuestList[i].sum,
                GuestList[i].time);
    }

    /* 打印保存完毕提示 */
    printf("Save Data to D:\\dat.txt\n");
    fclose(fp);
}

void Search(int)
{

}

void Update(int)
{

}

void Delete(int *)
{

}

void Show(int i)
{
    printf("%d:%s:%d:%s\n",
           GuestList[i].number,
           GuestList[i].name,
           GuestList[i].sum,
           GuestList[i].time);
}
