#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;

bool enqueue(int data)
{
    
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Error in allocating memory\n");
        return false;
    }
    temp->data = data;
    temp->next = NULL;

    if(rear == NULL)
    {
           rear = front = temp;
    }
    else
    {
        front->next = temp;
        front = temp;
    }
    return true;
}


int dequeue()
{
    if(front == NULL)
    {
        printf("Queue empty\n");
        return -1;
    }

    int data = rear->data;
    node *temp = rear;
    if(front == rear)
        front = rear = NULL;
    else
        rear = rear->next;
    free(temp); 
    return data;
}


int main(int argc, char *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    enqueue(60);
    enqueue(70);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    return 0;    
}
