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
list_t pa(list_t list);
list_t pb(list_t list);
list_t sb(list_t list);
list_t sa(list_t list);

void main(int ac, char** av)
{
    list_t list; 
    int i = 0;
    int j = 0;
    int b = 0;
    list = initialization(list, ac, av);
    while (1) {//(check_end(list, ac) != 0) {
        if (check_end(list, ac) == 0)
            break;
        while (list.a[0] < list.a[1]) {
            list = pb(list);
            my_putchar(' ');
            j++;
        }
        list = sa(list);
        if (check_end(list, ac) == 0)
            break;
        my_putchar(' ');
        while (j != 0) {
            list = pa(list);
            if (check_end(list, ac) == 0) {
                b = 1;
                break;
            }
            my_putchar(' ');
            j--;
        }
        if (b == 1)
            break;
        
    }
    /*
    while (i != list.sa) {
        my_put_nbr(list.a[i]);
        my_putchar(' ');
        i++; 
    }
    */
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
        if (list.a[i] > list.a[i + 1] || list.sb != 0) {
            return (1);
        }
        i++;
    }
    my_putchar('\n');
    return (0);
}

list_t pa(list_t list)
{
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int *tmp2 = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 0;
    
    tmp[0] = list.b[0];
    while (i != list.sa) {
        tmp[i + 1] = list.a[i];
        i++;
    }
    list.a = tmp;
    i = 1;
    while (i != list.sb) {
        tmp2[i - 1] = list.b[i];
        i++;
    }
    list.b = tmp2;
    list.sa += 1;
    list.sb -= 1;
    my_putstr("pa");
    return (list);
}

list_t pb(list_t list)
{
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int *tmp2 = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 0;

    tmp[0] = list.a[0];
    while (i != list.sb) {
        tmp[i + 1] = list.b[i];
        i++;
    }
    list.b = tmp;
    i = 1;
    while (i != list.sa) {
        tmp2[i - 1] = list.a[i];
        i++;
    }
    list.a = tmp2;
    list.sa -= 1;
    list.sb += 1;
    my_putstr("pb");
    return (list);
}

list_t sa(list_t list)
{
    int tmp = list.a[0];
    
    list.a[0] = list.a[1];
    list.a[1] = tmp;

    my_putstr("sa");
    return (list);
}

list_t sb(list_t list)
{
    int tmp = list.b[0];

    list.b[0] = list.b[1];
    list.b[1] = tmp;

    my_putstr("sb");
    return (list);
}
