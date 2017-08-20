#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;


bool add_node(node **head, int data)
{
    node *root = *head;
    node *prev = NULL;

    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Error in memory allocation\n");
        return false;
    }
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if(root == NULL)
    {
        *head = temp;   
    }
    else
    {
        while(root != NULL)
        {
            prev = root;
            if(root->data > temp->data)
            {
                root = root->lchild;    
            }
            else
            {
                root = root->rchild;    
            }
        }
        if(prev->data > temp->data)
        {
            prev->lchild = temp;
        }
        else
        {
            prev->rchild = temp;
        }
    }
}

void inorder(node *head)
{
    if(head != NULL)
    {
        inorder(head->lchild);
        printf("%d -> ", head->data);
        inorder(head->rchild);
    }
}

void preorder(node *head)
{
    if(head != NULL)
    {
        printf("%d -> ", head->data);
        preorder(head->lchild);
        preorder(head->rchild);
    }
}

void postorder(node *head)
{
    if(head != NULL)
    {
        postorder(head->lchild);
        postorder(head->rchild);
        printf("%d -> ", head->data);
    }
}

int get_height(node *head)
{
    if(head != NULL)
    {
        int lLen = get_height(head->lchild);    
        int rLen = get_height(head->rchild);
        return (lLen > rLen? ++lLen: ++rLen);
    }
    return 0;
}

void print_level(node *head, int level)
{
    if(head == NULL)
        return;

    if(level == 0)
    {
        printf("%d -> ", head->data);   
        return;
    }
    print_level(head->lchild, level - 1);
    print_level(head->rchild, level - 1);
}


void level_tree_traversal(node *head)
{
    int i = 0;
    for(i = 0; i < get_height(head); i++)
    {
        print_level(head, i);    
        printf("\n");
    }
    
}

void recursive(node *head, int direction)
{
    if(head == NULL)
        return;

    if(direction == 0)
    {
        recursive(head->lchild, 0);    
        printf("-> %d ", head->data);
    }
    else
    {
        printf("-> %d ", head->data);
        recursive(head->rchild, 1);    
    }
}


void top_view(node *head)
{
    recursive(head->lchild, 0);
    printf("-> %d ", head->data);
    recursive(head->rchild, 1);
}

int main(int argc, char *argv[])
{
    node *head = NULL;
    add_node(&head, 25);
    add_node(&head, 10);
    add_node(&head, 5);
    add_node(&head, 50);
    add_node(&head, 75);
    add_node(&head, 15);
    add_node(&head, 37);
    add_node(&head, 17);
    add_node(&head, 80);
    add_node(&head, 90);
    add_node(&head, 18);
    add_node(&head, 19);
    add_node(&head, 20);
    add_node(&head, 21);
    inorder(head);
    printf("\n");
    preorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
    printf("Height = %d\n", get_height(head));
    level_tree_traversal(head);
    top_view(head);
    printf("\n");
    return 0;    
}
