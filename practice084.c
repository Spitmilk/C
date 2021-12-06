//题目：一个偶数总能表示为两个素数之和。
#include <stdio.h>

int main()
{
    int i,j,k,p;
    int prime;
    for (i=4;i<100;i+=2)
    {   
        for(j=2;j<i/2+1;j++)
        {
            prime=0;
            for(k=2;k<j;k++)
            {
                if (j%k == 0) prime++;
                if (prime > 0) break;
            }
            if (prime == 0) 
            {
                p=i-k;
                for (k=2;k<p/2+1;k++)
                {
                    if (p%k == 0) prime++;
                    if (prime > 0) break;
                }
                if (prime == 0) printf("%d=%d+%d \n",i,p,i-p);               
            }
        }
    }
    return 0;
}