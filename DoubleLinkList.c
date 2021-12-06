#include <stdio.h>
#include <stdlib.h>
typedef struct DLinkList
{
    int data;
    struct DLinkList *prior,*next;
}DLinkList;

void CreateList (DLinkList *head)
{
    head = (DLinkList*)malloc(sizeof(DLinkList));
    head->prior = NULL;
    head->next = NULL;
    return;
}

void DeleteList (DLinkList *head)
{
    DLinkList *deleteNode;
    while (head)
    {
        deleteNode = head;
        head = head->next;
        free(deleteNode);
    }
    return;
}

void AddElement (DLinkList *head,int data)
{
    DLinkList *node,*prior;
    node = head;
    prior = node;
    while (node)
    {
        prior = node;
        node = node->next;
    }
    node = (DLinkList*)malloc(sizeof(DLinkList));
    node->data = data;
    prior->next = node;
    node->prior = prior;
    node->next = NULL;
    return;
}

void InitList(DLinkList *head)
{
    DLinkList *node;
    node = head;
    while (node)
    {
        node->data = 0;
        node = node->next;
    }
    return;
}

DLinkList* GetPrior(DLinkList *node)
{
    return node->prior;
}

DLinkList* GetNext(DLinkList *node)
{
    return node->next;
}

void PrintList(DLinkList *head)
{
    DLinkList *node;
    int i=0;
    node = head;
    while (node)
    {
        printf ("%d:%d ",i++,node->data);
        node = node->next;
    }
    return;
}

int main()
{
    DLinkList *head;
    CreateList(head);
    InitList(head);
    for (int i=0;i<20;i++)
    {
        AddElement (head,i);
    }
    //PrintList(head);
    DeleteList(head);
    PrintList(head);
    return 0;
}