#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SET_BIT(num, pos) ((num) |= (1 << (pos)))
#define CLR_BIT(num, pos) ((num) &= ~(1 << (pos)))
#define IS_BIT_SET(num, pos) ((1 << (pos)) & (num)? true : false)


void check_endianness()
{
    int data = 1;
    char *c = (char *)&data;
    if(*c == 1)
        printf("Little endian\n");    
    else
        printf("Big endian\n");    
}

int num_of_set_bits(int num)
{
    int size_in_bits = 8*sizeof(num);
    int count = 0;
    int i = 0;
    for(i = 0; i < size_in_bits; i++)
    {
        if(IS_BIT_SET(num, i))
            count++;    
    }
    return count;
}

int my_atoi(char *str)
{
    int value = 0;
    int count = 0;
    int str_len = strlen(str);
    while(*str != '\0')
    {
        value += ((((*str++)) - '0')*(pow(10, (str_len - count - 1))));  
        count++;
    }
    return value; 
}


int main(int argc, char *argv[])
{
    check_endianness();
    int num = 10;
    char str[10] = "1101";
    printf("%d\n", SET_BIT(num, 2));
    //printf("%d\n", CLR_BIT(num, 2));
    printf("%d\n", IS_BIT_SET(num, 2));
    printf("%d\n", num_of_set_bits(num));
    printf("%d\n", my_atoi(str));
    return 0;    
}

