//This program for print all prime number < 100 
#include <stdio.h>

int main()
{
    int i,j,k;
    for (i=2;i<101;i++)
    {
        k=0;
        for (j=2;j<i/2+1;j++)
        {
            if (i % j == 0) k++;  
            if (k > 0) break;       
        }
        if (k == 0) printf("%d ",i);
    }
    printf("\n");
    return 0;
}