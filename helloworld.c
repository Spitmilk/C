#include <stdio.h>
char str[20];
int main()
{
    str[0]='5';
    str[1]='4';
    str[2]='\0';
    printf("Hello World! %s\n",str);
    return 0;
}