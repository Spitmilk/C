#include <stdio.h>
//#include <string.h>
char mystr[100] ="Hello this program for reverse this line.";

void reverse(char* str)
{
    int len=0,i=0;
    char *strT,char1;
    len = 0;
    i = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }

    strT = str - 1;
    str -= 41;

    for (i=0;i<=len/2;i++)
    {
        char1 = *str;
        *str = *strT;
        *strT = char1;
        str++;
        strT--;
    }
    return;
}

int main()
{
    printf("%s \n",mystr);
    reverse((char*)&mystr);
    printf("%s \n",mystr);
    return 0;
}