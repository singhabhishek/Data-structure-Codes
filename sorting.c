#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(int *data, int size)
{
    int i, j;
    for(i = 0; i < (size - 1); i++)
    {
        for(j = i; j < size; j++)
        {
            if(data[i] > data[j])
            {
                swap(&data[i], &data[j]);
            }
        }
    }
}

void bubble_sort(int *data, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < (size - i - 1); j++)
        {
            if(data[j] > data[j + 1])
            {
                swap(&data[j], &data[j+1]);
            }
        }
    }
}

/*void insertion_sort(int *data, int size)
{
    int i, j, k;
    for(i = 1; i < size; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(data[j] > data[i])
            {
                int temp1 = data[i];
                int temp2;
                for(k = j; k <= i; k++)
                {
                    temp2 = data[k];
                    data[k] = temp1;
                    temp1 = temp2;
                }
            }
        }
    }
}*/

void insertion_sort(int *data, int size)
{
    int i, j, k;
    for(i = 1; i < size; i++)
    {
        for(j = i - 1; j >= 0; j--)
        {
            if(data[j] > data[i])
            {
                int temp = data[i];
                for(k = j; k >= 0; k--)
                {
                    if(data[k] > temp)
                    {
                        data[k+1] = data[k];
                        if(k == 0)
                        {
                            data[k] = temp;
                            break;
                        }
                    }
                    else
                    {
                        data[k+1] = temp;
                        break;
                    }
                }
            }
        }
    }
}

int partition(int *data, int start, int end)
{
    int pivot = data[end];
    int p_index = start;
    int i;
    for(i = start; i < end; i++)
    {
        if(data[i] <= pivot)
        {
            swap(&data[i], &data[p_index]);
            p_index++;
        }
    }
    swap(&data[p_index], &data[end]);
    return p_index;
}

void quick_sort(int *data, int start, int end)
{
    if(start < end)
    {
        int index = partition(data, start, end);
        quick_sort(data, start, index - 1);
        quick_sort(data, index + 1, end);
    }
}

void print_array(int *data, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d  ", data[i]);    
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int data_array_selection[ARRAY_SIZE] = {5, 6, 2, 4, 7, 0, 8, 1, 3, 1};
    int data_array_bubble[ARRAY_SIZE] = {5, 6, 2, 4, 7, 0, 8, 1, 3, 1};
    int data_array_insertion[ARRAY_SIZE] = {5, 6, 2, 4, 7, 0, 8, 1, 3, 1};
    int data_array_quick[ARRAY_SIZE] = {5, 6, 2, 4, 7, 0, 8, 1, 3, 1};

    printf("Unsorted Data::\n");
    print_array(data_array_selection, ARRAY_SIZE);
    
    printf("Selection sorted data::\n");
    selection_sort(data_array_selection, ARRAY_SIZE);
    print_array(data_array_selection, ARRAY_SIZE);
    
    printf("Bubble sorted data::\n");
    bubble_sort(data_array_bubble, ARRAY_SIZE);
    print_array(data_array_bubble, ARRAY_SIZE);
    
    printf("Insertion sorted data::\n");
    insertion_sort(data_array_insertion, ARRAY_SIZE);
    print_array(data_array_insertion, ARRAY_SIZE);
    
    printf("Quick sorted data::\n");
    quick_sort(data_array_quick, 0, ARRAY_SIZE - 1);
    print_array(data_array_quick, ARRAY_SIZE);
   
   return 0;
}
