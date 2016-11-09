/* c37 */

#include <stdio.h>
#include <stdlib.h>
int fun(int m,int n)
{
    int i,j=0,k;
    if(n<m)
        return 0;
    
    if(n==m||m==1)
        return 1;
    
    for(i=1;i<=m;i++)
        j=j+fun(i,n-m);
    
    return  j;
}

int main()
{
    int i,j,k=0;
    int val;
    scanf("%d", &val);
    
    for(i=1;i<val;i++)
        k=k+fun(i,val);
    
    printf("%d\n",k);
    system("pause");
    return 0;
}
