/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** m
*/

#include "my.h"

typedef struct my_lists {
    int *a;
    int	*b;
} list_t;

int check_end(list_t list, int ac);
list_t bubble_sort_array(list_t list, int ac);

void main(int ac, char** av)
{
    list_t list; 
    int i = 0;
    
    list.a  = malloc(sizeof(int) * ac);
    while (i != ac) {
        list.a[i] = my_getnbr(av[i]);
        i++;
    }
    if (check_end(list, ac) == 0)
        return;
}

int check_end(list_t list, int ac)
{
    int i = 0;

    while (i != ac - 1) {
        if (list.a[i] > list.a[i + 1])
            return (1);
        i++;
    }
    my_putchar('\n');
    return (0);
}

list_t bubble_sort_array(list_t list, int ac)
{
    int i = 0;
    int tmp;
    
    while (i != ac) {
        
    }
}
