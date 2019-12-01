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
    int sa;
    int sb;
} list_t;

list_t initialization(list_t list, int ac, char **av);
int check_end(list_t list, int ac);
list_t bubble_sort_array(list_t list, int ac);
list_t pa(list_t list, int ac);
list_t pb(list_t list, int ac);

void main(int ac, char** av)
{
    list_t list; 

    list = initialization(list, ac, av);
    //list = pb(list, ac);
    //my_put_nbr(list.b[0]);
    if (check_end(list, ac) == 0)
        return;
}

list_t initialization(list_t list, int ac, char **av)
{
    int i = 0;
    
    list.a  = malloc(sizeof(int) * ac);
    list.b  = malloc(sizeof(int) * ac);
    list.sa = ac - 1;
    list.sb = 0;
    while (i != list.sa) {
        list.a[i] = my_getnbr(av[i + 1]);
        i++;
    }    
    return (list);
}
    

int check_end(list_t list, int ac)
{
    int i = 0;

    while (i != list.sa - 1) {
        if (list.a[i] > list.a[i + 1]) {
            return (1);
        }
        i++;
    }
    my_putchar('\n');
    return (0);
}

list_t pa(list_t list, int ac)
{
    int *tmp = malloc(sizeof(int) * ac);
    int *tmp2 = malloc(sizeof(int) * ac);
    int i = 0;
    
    tmp[0] = list.b[0];
    while (list.a[i] != NULL) {
        tmp[i + 1] = list.a[i];
        i++;
    }
    list.a = tmp;
    i = 1;
    while (list.b[i] != NULL) {
        tmp2[i - 1] = list.b[i];
        i++;
    }
    list.b[i] = NULL;
    list.b = tmp2;
}

list_t pb(list_t list, int ac)
{
    int *tmp = malloc(sizeof(int) * ac);
    int *tmp2 = malloc(sizeof(int) * ac);
    int i = 0;

    tmp[0] = list.a[0];
    while (list.b[i] != NULL) {
        tmp[i + 1] = list.b[i];
        i++;
    }
    list.b = tmp;
    i = 1;
    while (list.a[i] != NULL) {
        tmp2[i - 1] = list.a[i];
        i++;
    }
    list.a[i] = NULL;
    list.a = tmp2;
}

list_t bubble_sort_array(list_t list, int ac)
{
    int i = 0;
    int tmp;
    
    while (i != ac) {
        
    }
}
