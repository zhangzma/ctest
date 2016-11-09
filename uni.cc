
#include <iostream>
#include <memory.h>

using namespace std;

int del(char s[])
{
    int i=0,num=0,j,k1,k,flag;
    
    while(s[i]) {
        j    = i+1;
        flag = 1;
        while(s[j])
        {
            if (s[j] == s[i])
            {
                k     = j+1;
                k1    = j;
                flag  = 0;
                num  += 1;
                
                while(s[k])
                {
                    s[k-1] = s[k];
                    k++;
                }
                s[k-1] = '\0';
                
                if (flag == 0)
                {
                    j = k1;
                }
                break;   
            }
            else 
                j++;
        }
        i++;
    }
    
    return num;
}

int main(void)
{   char a[40];
    memset(a, 40, '\0');
    cout<<"请输入一个字符数组:"<<'\n';
    cin.getline(a,40);
    del(a);
    cout<<'\n'<<"删除后的字符数组为:"<<'\n'<<a<<'\n';

    return 0;
}
