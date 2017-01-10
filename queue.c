#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Error in memory allocation\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
        
    }
    else
    {
        front->next = temp;
        front = temp;
    }
}

int delete()
{
    if(rear == front)
    {
        printf("Queue Empty\n");
        return -1;
    }
    int data = rear->data;
    struct node *temp = rear;
    rear = rear->next;
    free(temp);
    return data;
}

int main(int argc, char *argv[])
{
    insert(10);    
    insert(20);    
    insert(30);    
    insert(40);    
    insert(50);
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    
    return 0;
}
