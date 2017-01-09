#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add_node_last(struct node **head, int data)
{
    struct node *temp = *head;
    if(temp == NULL)
    {
        temp = (struct node*)malloc(sizeof(struct node));  
        *head = temp;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;    
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->data = data;
    temp->next = NULL;
}

void add_node_first(struct node **head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(*head == NULL)
    {
        *head = temp;    
    }
    else
    {
        struct node *first = temp;
        temp->next = *(head);
        *head = temp;
    }
}

void add_node_Nth(struct node **head, int data, int index)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    int count = 0;
    struct node *prev = *head;
    struct node *current = *head;
    while((count != index) && (current != NULL))
    {
        prev = current;
        current = current->next;
        count++;
    }
    if((current == NULL) && (count != index))
    {
        printf("Out of range. Can't add.\n");
        return;
    }
    if(count == 0)
    {
        temp->next = *head;  
        *head = temp;
    }
    else
    {
        prev->next = temp;
        temp->next = current;
    }
}

void print_data(struct node *head)
{
    while((head != NULL))    
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void print_reverse_data(struct node *head)
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        printf("%d\n", head->data);
        return;
    }
    print_reverse_data(head->next);
    printf("%d\n", head->data);
}

void delete_node_index(struct node **head, int index)
{
    if(*head == NULL)
    {
        return;
    }
    else
    {
        struct node *temp = *head;
        struct node *prev = *head;
        int count = 0;
        while((count != index) && (temp != NULL))
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(temp == NULL)
        {
            printf("Out of bound. Can't delete\n");    
        }
        else
        {
            if(index == 0)
            {
                *head = temp->next;    
            }
            else
            {
                prev->next = temp->next;
            }
        }
    }
}

void delete_node_by_value(struct node **head, int value)
{
    if(*head == NULL)
    {
        return;
    }
    else
    {
        struct node *temp = *head;
        struct node *prev = *head;
        int count = 0;
        while(temp != NULL)
        {
            if(temp->data == value)
                break;
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(temp == NULL)
        {
            printf("Out of bound. Can't delete\n");    
        }
        else
        {
            if(count == 0)
            {
                *head = temp->next;    
            }
            else
            {
                prev->next = temp->next;
            }
        }
    }
}

void reverse(struct node **head)
{
    struct node *temp = *head;
    if((temp == NULL))
    {
        return;    
    }
    
    if((temp->next == NULL))
    {
        return;    
    }
   
    struct node *prev = *head;
    struct node *current = *head;
    struct node *next = *head;
    current = prev->next;
    prev->next = NULL;
    while(next != NULL)
    {
        next = current->next;
        current->next = prev;
        *head = current;
        prev = *head;
        current = next;
   }
}

// Bubble sort
void sort_list(struct node **head)
{
    if(*head == NULL)
    {
        return;
    }
    if((*head)->next == NULL)
    {
        return;
    }
    else
    {
        for(struct node *iter1 = *head; iter1 != NULL; iter1 = iter1->next)
        {
            for(struct node *iter2 = iter1->next; iter2 != NULL; iter2 = iter2->next)
            {
                if(iter1->data > iter2->data)
                {
                    int temp = iter1->data;
                    iter1->data = iter2->data;
                    iter2->data = temp;
                }
            }
        }
    }
}

int get_node_from_tail(struct node *head, int index)
{
    if(index < 0)
    {
        printf("Not a vaid index\n");
        return 0;
    }
    struct node *iter1 = head;
    struct node *iter2 = head;
    int count = 0;
    while((count != index) && (iter2->next != NULL))
    {
        iter2 = iter2->next;   
        count++;
    }

    if(iter2->next == NULL)
    {
        printf("Not a valid index\n");   
        return 0;
    }
    while(iter2->next != NULL)
    {
        iter2 = iter2->next;
        iter1 = iter1->next;
    }

    return iter1->data;
}

void remove_duplicates(struct node *head)
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        return;    
    }
    else
    {
        struct node *iter1 = head;
        struct node *iter2 = head;
        struct node *prev = head;

        for(iter1 = head; iter1 != NULL; iter1 = iter1->next)
        {
            prev = iter1;
            for(iter2 = iter1->next; iter2 != NULL; iter2 = iter2->next)
            {
                if(iter1->data == iter2->data)
                {
                    prev->next = iter2->next;
                    iter2 = prev;
                }
                prev = iter2;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    struct node *head = NULL;
    add_node_last(&head, 10);
    add_node_last(&head, 20);
    add_node_last(&head, 30);
    add_node_first(&head, 40);
    add_node_first(&head, 50);
    add_node_first(&head, 60);
    print_data(head);   
    delete_node_index(&head, 0);
    printf("After delete\n");
    print_data(head);   
    delete_node_index(&head, 2);
    printf("After delete\n");
    print_data(head);   
    delete_node_index(&head, 3);
    printf("After delete\n");
    print_data(head);   
    delete_node_index(&head, 6);
    printf("After delete\n");
    print_data(head);
    delete_node_by_value(&head, 50);
    printf("After delete\n");
    print_data(head);
    delete_node_by_value(&head, 20);
    printf("After delete\n");
    print_data(head);
    add_node_Nth(&head, 100, 0);
    printf("Add 100 at position 0\n");
    print_data(head);
    //add_node_Nth(&head, 200, 1);
    printf("Add 200 at position 1\n");
    print_data(head);
    add_node_Nth(&head, 300, 3);
    printf("Add 300 at position 3\n");
    print_data(head);
    add_node_Nth(&head, 700, 0);
    printf("Add 700 at position 0\n");
    print_data(head);
    add_node_Nth(&head, 500, 7);
    printf("Add 500 at position 7\n");
    print_data(head);
    printf("Print reverse\n");
    print_reverse_data(head);
    printf("Reverse list\n");
    reverse(&head);
    print_data(head);
    printf("Sorted list\n");
    sort_list(&head);
    print_data(head);
    printf("Index 3 = %d\n", get_node_from_tail(head, 3));
    add_node_last(&head, 10);
    add_node_last(&head, 20);
    add_node_last(&head, 10);
    add_node_last(&head, 10);
    add_node_last(&head, 10);
    add_node_last(&head, 10);
    add_node_last(&head, 10);
    add_node_last(&head, 20);
    add_node_first(&head, 40);
    add_node_first(&head, 40);
    add_node_Nth(&head, 100, 4);
    add_node_Nth(&head, 200, 6);
    add_node_last(&head, 200);
    print_data(head);
    printf("After removing duplicates\n");
    remove_duplicates(head);
    print_data(head);


    return 0;    
}


