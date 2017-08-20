#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *top = NULL;

bool push(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Error in allocating memory\n");
        return false;
    }
    temp->data = data;
    temp->next = NULL;

    if(top == NULL)
    {
        top = temp;    
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    return true;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack empty\n");
        return -1;
    }
    int data = top->data;
    node *temp = top;
    top = top->next;
    free(temp);
    return data;    
}


int main(int argc, char *argv[])
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    push(60);
    push(70);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;    
}
