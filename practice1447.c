/**
 * Note: The returned array must be malloced, assume caller calls free().
 给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 */
 #include <stdio.h>
 #include <stdlib.h>

int gcd(int a,int b)
{
    int remainder;
    do
    {
        remainder=a%b;
        a=b;
        b=remainder;
    }while(remainder!=0);
    if (a==1) return 0;
    else return 1;
}

char ** simplifiedFractions(int n,int* returnSize){
    *returnSize=0;
    char** reValue = (char**)calloc(n*(n-1)/2+1, sizeof(char*));
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<=n;j++)
        {            
            if (i/j>0 || gcd(j,i) && i!=1) continue;
            else 
            {
                reValue[*returnSize] = (char*)calloc((n/10+1)*4, sizeof(char));
                sprintf(reValue[*returnSize], "%d/%d", i,j);
                *returnSize+=1;
            }
        }
    }
    return reValue;
} 
int main()
{
    char **p;
    int *a;
    p=simplifiedFractions(81,a);
    for (int i=0;i<*a;i++)
    {
        printf("%s ",p[i]);
    }    
    return 0;
}