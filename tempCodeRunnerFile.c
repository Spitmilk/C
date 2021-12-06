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
    char** reValue = (char**)calloc(100, sizeof(char*));
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<=n;j++)
        {            
            if (i/j>0 || gcd(j,i) && i!=1) continue;
            else 
            {
                reValue[*returnSize] = (char*)calloc(10, sizeof(char));
                sprintf(reValue[*returnSize], "%d/%d", i,j);
                *returnSize+=1;
            }
        }
    }
    return reValue;
}