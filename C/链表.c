#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pNext;
};
struct Node *createList()
{
    struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));
    headNode->pNext = NULL;
    return headNode;
}
struct Node *creatNewNodes(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}
void headInsertNode(struct Node *headNode, int data)
{
    struct Node *newNode = creatNewNodes(data);
    newNode->pNext = headNode->pNext;
    headNode->pNext = newNode;
}
void printNode(struct Node *list)
{
    struct Node *lastNode = list->pNext;
    while (lastNode)
    {
        printf("%d \n", lastNode->data);
        lastNode = lastNode->pNext;
    }
    printf("\n");
}
void updateNode(struct Node *list, int data, int editData)
{
    struct Node *lastNode = list->pNext;
    if (list == NULL)
    {
        printf("dot`t updateNode \n");
    }
    while (lastNode->data != data)
    {
        lastNode = lastNode->pNext;
        if (lastNode == NULL)
        {
            printf("notfount \n");
        }
    }
    lastNode->data = editData;
}
void deleteNode(struct Node *list, int data)
{
    struct Node *lastNode = list->pNext;
    struct Node *slowNode;
    if (list == NULL)
    {
        printf("dot`t deleteNode \n");
    }
    while (lastNode->data != data)
    {
        slowNode = lastNode;
        lastNode = lastNode->pNext;
        if (lastNode == NULL)
        {
            printf("notfount \n");
        }
    }
    slowNode->pNext = lastNode->pNext;
    lastNode->pNext = NULL;
}
int main()
{
    struct Node *list1 = createList();
    struct Node *list2 = createList();
    headInsertNode(list1, 4);
    headInsertNode(list1, 2);
    headInsertNode(list1, 1);
    printNode(list1);
    printf("ok");
    return 0;
} 