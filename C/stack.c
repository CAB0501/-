#include <stdio.h>
#include <stdlib.h>
#define size 10
#define bool int
#define true 0
#define false 1

typedef int dataType; 
typedef struct stack
{ 
    dataType num[size];
    int count;
}stack;

stack *createStack()
{  
    stack *st = (stack *)malloc(sizeof(stack*));
    if (st == NULL)
    {
        printf("结构体空");
        return NULL;
    }
    st->count = 0;
    return st;
}

bool push(stack *st, dataType data)
{
    if (st->count == size)
    {
        return false;
    }
    st->num[st->count] = data;
    st->count++;
    return true;
}

dataType pop(stack *st)
{
    if (st->count == 0)
    {
        printf("空栈");
        return 0;
    }
    return st->num[--st->count];
}

void printStack(stack *st)
{
    int i = st->count;
    while (i > 0)
    {
        printf("%d ", st->num[i-1]);  
        i--;
    }
    printf("\r\n");  
}

int main(){  
    int i=5,j=5; 
    stack* st = createStack();
    printf("start_push: \r\n");
    while(i--)
    {
        push(st,i);
        printStack(st);
    }  
    printf("start_pop: \r\n");
    while(j--)
    {
        printStack(st);
        pop(st);
    }

    return 0;
}