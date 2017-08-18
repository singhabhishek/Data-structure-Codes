#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG 0

typedef struct node
{
    int data;
    struct node *next;
}node;


int get_size(node *head)
{
    int count = 0;
#ifdef DEBUG
    printf("Print size \n");
#endif
    if(head == NULL)
    {
        return 0;
    }

    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


bool add_node_end(int data, node **head)
{
#ifdef DEBUG
    printf("Add node end 1\n");
#endif
    node *temp = *head;
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error in allocating memory!\n");
        return false;
    }
    new_node->data = data;
    if(temp == NULL)
    {
        *head = new_node;
    }
    else 
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
#ifdef DEBUG
    printf("Add node end 2\n");
#endif
    return true;    
}


bool add_node_start(int data, node **head)
{
#ifdef DEBUG
    printf("Add node start 1\n");
#endif
    node *temp = *head;
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error in allocating memory!\n");
        return false;
    }
    new_node->data = data;

    new_node->next = temp;
    *head = new_node;
#ifdef DEBUG
    printf("Add node start 2\n");
#endif
    return true;    
}


bool add_node_at_position(int data, node **head, int position)
{
#ifdef DEBUG
    printf("Add node at position 1\n");
#endif
    node *temp = *head;
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error in allocating memory!\n");
        return false;
    }
    new_node->data = data;
    new_node->next = NULL;
    
    if((position < 0) || (position > get_size(temp)))
    {
        printf("Invalid position\n");
        return false;
    }

    int count = 0;

    if(position == 0)
    {
        new_node->next = temp;
        *head = new_node;
    }
    else
    {
        while((temp != NULL) && (count < (position-1)))
        {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    
#ifdef DEBUG
    printf("Add node at position 2\n");
#endif
    return true;    
}


void print_node(node *head)
{
#ifdef DEBUG
    printf("Print node \n");
#endif
    if(head == NULL)
    {
        printf("Empty  ..\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d -> ", head->data);    
        head = head->next;
    }
    printf("\n");
}

bool delete_node_start(node **head)
{
    node *temp_head = *head;
    *head = (*head)->next;
    free(temp_head);
    return true;
}


bool delete_node_end(node **head)
{
    node *curr = *head;
    node *prev = NULL;
    if(curr == NULL)
        return true;
    else
    {
        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }
    return true;
}


bool delete_node_at_position(node **head, int position)
{
    node *curr = NULL;
    node *prev = *head;
    node *n = *head;
    int count = 0;

    if(position == 0)
        delete_node_start(head);
    else if(position == (get_size(*head)-1))
        delete_node_end(head);
    else
    {
        while((n->next != NULL) && (count < (position+1)))
        {
            curr = n;
            n = n->next;
            if(count > 1)
            {
                prev = prev->next;    
            }
            count++;
        }
        prev->next = curr->next;
        free(curr);
    }
    
    return true;    
}

void print_reverse(node *head)
{
    if(head != NULL)  
        print_reverse(head->next);
    else
        return;
    printf("%d -> ", head->data);
}

node *reverse_recursive(node *head, node *prev)
{
    if(head == NULL)
        return prev;
    node *temp = head->next;
    head->next = prev;
    return reverse_recursive(temp, head);
}


void reverse(node **head)
{
    node *prev = NULL;
    node *curr = *head;
    node *n = *head;
    if(curr == NULL)
        return;
    else if(curr->next == NULL)
        return;
    else
    {
        n = n->next;
        while(n != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = n;
            n = n->next;
        }
        curr->next = prev;
        prev = curr;
    }
    *head = prev;
}

bool delete_node_by_value(node **head, int value)
{
    int count = -1;
    node *temp = *head;
    while(temp != NULL)
    {
        if(temp->data == value)
            break;
        temp = temp->next;
        count++;
    }
    if(count == -1 || count >= (get_size(*head) - 1))
    {
        printf("Invalid data!\n");   
        return false;
    }
    delete_node_at_position(head, ++count );
    return true;
}

int main(int argc, char *argv[])
{
    node *head = NULL;
    add_node_end(10, &head);
    add_node_end(20, &head);
    add_node_end(30, &head);
    add_node_end(40, &head);
    add_node_end(50, &head);
    add_node_end(80, &head);
    add_node_end(60, &head);
    add_node_end(90, &head);
    add_node_end(70, &head);
    add_node_end(60, &head);
    add_node_start(5, &head);
    add_node_start(6, &head);
    add_node_start(7, &head);
    print_node(head);
    printf("Size = %d\n", get_size(head));
    add_node_at_position(0, &head, 0);
    add_node_at_position(100, &head, 14);
    add_node_at_position(51, &head, 0);
    add_node_at_position(52, &head, 7);
    print_node(head);
    delete_node_start(&head);
    delete_node_start(&head);
    print_node(head);
    delete_node_end(&head);
    delete_node_end(&head);
    print_node(head);
    //delete_node_at_position(&head, 0);
    //delete_node_at_position(&head, 1);
    delete_node_at_position(&head, 12);
    print_node(head);
    //print_reverse(head);
    //printf("\n");
    head = reverse_recursive(head, NULL);
    print_node(head);
    reverse(&head);
    print_node(head);
    return 0;    
}
