#include <stdio.h>

int numList[10]={6,4,8,1,4,7,9,9,4,2};

void switchTwo(int *x,int *y);

void switchTwo(int *x,int *y)
{
    int num;
    num = *x;
    *x = *y;
    *y = num;
    return;
}

int main()
{
    int i,j;
    for (i=0;i<10;i++)
    {
        for (j=i;j<10;j++)
        {
            if (numList[j]<numList[i])
            {
                switchTwo(&numList[i],&numList[j]);
            }
        }
    }
    for (i=0;i<10;i++) printf("%d ",numList[i]);
    printf ("\n");
    return 0;
}