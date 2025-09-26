#include <stdio.h>
void main()
{
    int m,i;
    scanf("%d",&m);
    i=1;
    while(i<=10)
    {
        printf("%d*%d=%d\n",m, i, m*i);
        i=i+1;
    }
}
