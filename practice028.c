//这个程序是反向打印一个5位数
#include <stdio.h>
#include <stdlib.h>
int num;
typedef struct ChainList //链表的结构体
{
    int value;
    struct ChainList *next;
}ChainList;
ChainList *head,*node,*pre;

void depart(int num) //分解num
{    
    node = (ChainList*) malloc (sizeof(ChainList));
    pre->next = node;
    if (num < 10) 
    {
        node->value = num;
        node->next = NULL;
        return;
    }
    else 
    {   
        node->value = num % 10;
        num -= node->value;
        num /= 10;
        pre = node;
        depart(num);
    }
}
int main()
{
    num = 12345;
    
    pre = (ChainList*) malloc (sizeof(ChainList));
    head = (ChainList*) malloc (sizeof(ChainList));
    head->value = 0;
    pre = head;
    depart(num);

    num =0;

    node = head;
    while (node)
    {
        num *= 10;
        num += node->value;
        node = node->next;
    }
    printf ("The reversed number is %d",num);
}