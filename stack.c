#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Error in memory allocation\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    if(top == NULL)
    {
        top = new_node;    
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

int pop()
{
    int value = 0;
    if(top == NULL)
    {
        printf("Stack Empty\n");
        return -1;
    }
    value = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return value;
}

int max_element()
{
    struct node *iter = top;
    if(iter == NULL)
    {
        printf("Stack empty\n");
        return -1;
    }

    int max = iter->data;
    while(iter != NULL)
    {
        if(iter->data > max)
        {
            max = iter->data;    
        }
        iter = iter->next;
    }
    return max;
}

int main(int argc, char *argv[])
{
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(100);
    push(200);
    push(300);
    push(400);

    printf("Max Element = %d\n", max_element());
    printf("Max Element = %d\n", max_element());
    printf("Max Element = %d\n", max_element());
    printf("Max Element = %d\n", max_element());
    printf("Max Element = %d\n", max_element());
    printf("Max Element = %d\n", max_element());

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("Max Element = %d\n", max_element());
    
    return 0;
}
