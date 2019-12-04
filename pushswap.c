
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
    long long average;
} list_t;

list_t initialization(list_t list, int ac, char **av);
int check_end(list_t list, int ac);
list_t pa(list_t list);
list_t pb(list_t list);
list_t sb(list_t list);
list_t sa(list_t list);
list_t rb(list_t list);
list_t ra(list_t list);
list_t rrb(list_t list);
list_t rra(list_t list);
list_t moyenne(list_t list);
float av_part1(list_t list);
float av_part2(list_t list);
void main(int ac, char** av)
{
    list_t list; 
    int i = 0;
    int j = 0;
    int b = 0;
    int x = 0;
    float moy1;
    float moy2;
    list = initialization(list, ac, av);
    while (1) {
        //moy1 = av_part1(list);
        //moy2 = av_part2(list);
        if (check_end(list, ac) == 0)
            break;
        while (list.a[0] <= list.a[1]) {
            list = pb(list);
            my_putchar(' ');
            j++;
        }
        while (list.a[0] > list.a[1]) {
            list = ra(list);
            my_putchar(' ');
        }
        if (check_end(list, ac) == 0)
            break;
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
    my_putchar('\n');
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
    list = moyenne(list);
    return (list);
}
    

int check_end(list_t list, int ac)
{
    int i = 0;

    if (list.sb != 0)
        return (1);
    while (i != list.sa - 1) {
        if (list.a[i] > list.a[i + 1] || list.sb != 0) {
            return (1);
        }
        i++;
    }
    my_putchar('\n');
    return (0);
}

list_t moyenne(list_t list)
{
    list.average = 0;
    int i = 0;

    while (i != list.sa) {
        list.average += list.a[i];
        i++;
    }
    list.average = list.average / i;
    return (list);
}

float av_part1(list_t list)
{
    long long nbr = 0;
    int i = 0;
    float nb;
    
    while (i != list.sa/2) {
        nbr += list.a[i];
        i++;
    }
    nb = nbr / i;
    return (nb);
}

float av_part2(list_t list)
{
    long long nbr = 0;
    int i = list.sa/2;
    float nb;
    
    while (i != list.sa) {
        nbr += list.a[i];
        i++;
    }
    nb = nbr / (i - list.sa/2);
    return (nb);
}

list_t rra(list_t list)
{
    int a = list.a[list.sa - 1];
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 0;
    
    while (i != list.sa) {
        tmp[i + 1] = list.a[i];
        i++;
    }
    tmp[0] = a;
    list.a = tmp;
    my_putstr("rra");
    return (list);
}

list_t rrb(list_t list)
{
    int b = list.b[list.sb - 1];
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 0;

    while (i != list.sb) {
        tmp[i + 1] = list.b[i];
        i++;
    }
    tmp[0] = b;
    list.b = tmp;
    my_putstr("rrb");
    return (list);
}

list_t ra(list_t list)
{
    int a = list.a[0];
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 1;
    
    while (i != list.sa) {
        tmp[i - 1] = list.a[i];
        i++;
    }
    tmp[i - 1] = a;
    list.a = tmp;
    my_putstr("ra");
    return (list);
}

list_t rb(list_t list)
{
    int b = list.a[0];
    int *tmp = malloc(sizeof(int) * (list.sa + list.sb + 1));
    int i = 1;

    while (i != list.sb) {
        tmp[i - 1] = list.b[i];
        i++;
    }
    tmp[i - 1] = b;
    list.b = tmp;
    my_putstr("rb");
    return (list);
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
