#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

void add_node(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Error in memory alloaction\n");    
    }
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if(*head == NULL)    
    {
        *head = temp;    
    }
    else
    {
        struct node *iter = *head;
        struct node *prev = *head;
        while(iter != NULL)
        {
            prev = iter;
            if(iter->data < temp->data) 
            {
                iter = iter->rchild;
                continue;
            }
            else
            {
                iter = iter->lchild;
                continue;
            }
        }
        if(temp->data > prev->data)
        {
            prev->rchild = temp;    
        }
        else
        {
            prev->lchild = temp;    
        }
    }
}

void inorder(struct node *head)
{
    if(head != NULL)
    {
        inorder(head->lchild);
        printf("%d ", head->data);
        inorder(head->rchild);
    }
}

void preorder(struct node *head)
{
    if(head != NULL)
    {
        printf("%d ", head->data);
        preorder(head->lchild);
        preorder(head->rchild);
    }
}

void postorder(struct node *head)
{
    if(head != NULL)
    {
        postorder(head->lchild);
        postorder(head->rchild);
        printf("%d ", head->data);
    }
}

int get_height(struct node *head)
{
    if(head == NULL)
    {
        return 0;    
    }
    int left_height = get_height(head->lchild);
    int right_height = get_height(head->rchild);

    if(left_height > right_height)
    {
        return ++left_height;
    }
    else
    {
        return ++right_height;    
    }
}

void recursive(struct node *head, int direction)
{
    if(head == NULL)
        return;
    if(direction == 0)
    {
        recursive(head->lchild, 0);
        printf("%d ", head->data);
    }
    else
    {
        printf("%d ", head->data);
        recursive(head->rchild, 1);
    }
}

void top_view(struct node *head)
{
    recursive(head->lchild, 0);
    printf("%d ", head->data);
    recursive(head->rchild, 1);
}

void print_level(struct node *head, int level)
{
    if(head == NULL)
    {
        return;    
    }

    if(level == 1)
    {
        printf("%d ", head->data);
    }
    else
    {
        print_level(head->lchild, level - 1);
        print_level(head->rchild, level - 1);
    }
}

void level_tree_traversal(struct node *head)
{
    int height = get_height(head);
    int i = 0;
    for(i = 0; i <= height; i++)
    {
        print_level(head, i);
    }
}

int main(int argc, char *argv[])
{
    struct node *head = NULL;
    add_node(&head, 10);
    add_node(&head, 5);
    add_node(&head, 15);
    add_node(&head, 50);
    add_node(&head, 37);
    add_node(&head, 75);
    add_node(&head, 25);
    printf("Inorder:: ");
    inorder(head);
    printf("\nPreorder:: ");
    preorder(head);
    printf("\nPostorder:: ");
    postorder(head);
    printf("\nHeigth of Tree = %d\n", get_height(head));
    printf("Top view:: ");
    top_view(head);
    printf("\nLevel view tree traversal:: ");
    level_tree_traversal(head);
    printf("\n");
    return 0;
}
