//题目：求0—7所能组成的奇数个数。
#include <stdio.h>

int main()
{
    int i,j,m;
    long n,sum;
    sum=0;
    for (i=0;i<8;i++)
    {
        switch (i) 
        {
            case 0 : 
                n=4;
                break;
            case 1 : 
                n=4*7;
                break;
            default : 
                m=1;
                for (j=1;j<i;j++)
                {
                    m*=8;
                    n=4*7*m;
                }           
        }
        sum+=n;
        printf ("%d \n",n);
    }
    printf ("Sum is:%d \n",sum);
    return 0;
}