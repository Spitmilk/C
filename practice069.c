//题目：有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
#include <stdio.h>
#include <stdlib.h>

typedef struct NumCircle 
{
    int IDnum;
    struct NumCircle* next;
}NumCircle;

int LastStand(int n,int kill) //建立函数，第一个参数为一圈的总人数，第二参数为报到出圈的对应数字
{
    int i;
    NumCircle *node,*head,*pre_node,*del_node; //pre_node用来保存前一个元素的指针

    del_node = NULL;
    head = NULL;
    node = (NumCircle*)malloc(sizeof(NumCircle)); //为链表分配第一块内存
    pre_node = NULL;
    head = node;//为链表保存一个入口
    pre_node = node;
    
    for (i=0;i<n-1;i++)
    {
        node = (NumCircle*)malloc(sizeof(NumCircle));//为后续链表分配内存
        pre_node->IDnum=i+1;//编号
        pre_node->next=node;//上个元素的next指针指向当前元素
        pre_node=node;
    }
    pre_node->IDnum=i+1;//为最后一个元素编号
    pre_node->next = head;//使最后一个元素的next指向表头从而形成一个圆环

    node = head;
    i=0;
    while (n>1)//只要人数n大于1就一直执行出圈规则
    {
        pre_node=node;
        i++;
        node=node->next;
        if (i>=kill-1) //判断是否报数大于kill 因为计数从0开始所以加修正值-1
        {
            i=0;
            n-=1;//减少人数
            pre_node->next=node->next;//上个元素的next指向下个元素直接跳过当前元素
            del_node=node;
            node=node->next;//当前元素变为下个元素
            free(del_node);//删除当前元素
        }
    }
    return node->IDnum;//返回剩下的唯一元素的编号
}

int main()
{
    int killstep,n;
    killstep = 3;
    
    printf("输入一圈人数:");
    scanf("%d",&n);
    
    printf("%d \n",LastStand(n,killstep));

    return 0;
}