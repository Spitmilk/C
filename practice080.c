//题目：海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，多了一个，这只 猴子把多的一个扔入海中，拿走了一份。第二只猴子把剩下的桃子又平均分成五份，又多了 一个，它同样把多的一个扔入海中，拿走了一份，第三、第四、第五只猴子都是这样做的， 问海滩上原来最少有多少个桃子？
#include <stdio.h>

int main()
{
    int n,j,i;
    for (i=4;i<10000;i+=4)
    {
        n = i;
        for(j=0;j<5;j++)
        {
             if(n % 4 !=0)
             {
                 break;
             }
             n /= 4;
             n *= 5;
             n++;
             if (j>=4) 
             {
                 printf("%d \n",n);
             }
        }       
    }
    return 0;
}