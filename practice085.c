//题目：判断一个素数能被几个9整除。
#include <stdio.h>

unsigned int GetLength(unsigned long num)
{
    int i=0;
    while (num>1)
    {
        num /= 10;
        i++;
    }
    return i;
}

int main()
{
    unsigned long num,num9;
    unsigned int length,i,j,remainder;
    printf("Please input a prime number:");
    scanf("%d",&num);

    num9=0;
    length=GetLength(num);
    for (i=0;i<length;i++)
    {
        num9*=10;
        num9+=9; 
    }
    i=0;
    while(i<1000)
    {
        remainder=num9%num;
        if (remainder==0) break;
        else 
        {
            num9=remainder*10;
            num9+=9;
        }
        i++;
    }
    if (i<1000) 
    {
        for (j=0;j<length+i;j++) printf("%d",9);
        printf("\n");
    }    
    else printf(" No limit! \n");
    return 0;
}