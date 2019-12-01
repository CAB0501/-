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
        printf("%d ", lastNode->data);
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
struct Node *mergeTwoLists(struct Node *l1, struct Node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct Node *l1EndNode = l1->pNext;

    while (l1EndNode->pNext != NULL)
    {
        l1EndNode = l1EndNode->pNext;
    }
    l1EndNode->pNext = l2->pNext;

    return l1;
}
struct Node *sortNode(struct Node *list)
{
    struct Node* head = list->pNext; 
    struct Node* end = NULL;
    while (head != end)
    {
        while(head->pNext != end){
            if (head->pNext->data < head->data)
            {
                int nodeData = head->pNext->data;
                head->pNext->data = head->data;
                head->data = nodeData;
            }
            head = head->pNext; 
        }
        end = head; 
        head = list->pNext;
    }
    return list;
}
int main()
{
    struct Node *list1 = createList();
    struct Node *list2 = createList();
    headInsertNode(list1, 4);
    headInsertNode(list1, 2);
    headInsertNode(list1, 1);
    headInsertNode(list2, 4);
    headInsertNode(list2, 3);
    headInsertNode(list2, 1);
    struct Node *list3 = mergeTwoLists(list1, list2);
    printNode(list3);
    struct Node *list4 = sortNode(list3);    
    printNode(list4); 
    return 0;
}
