/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** m
*/

#include "my.h"

int main(int ac, char** av)
{
    list_t list; 
    
    list = initialization(list, ac, av);
    list = initialization2(list, ac, av);
    list = initialization3(list, ac, av);
    if (check_sorted(list) == 0)
        return (0);
    list.i = 0;
    while (list.i < 32) {
        list.n = 0;
        list = part1_algo(list);
        list = part2_algo(list);
    }
    list = part3_algo(list);
    return (0);
}

int check_sorted(list_t list)
{
    int i = 1;

    list.a = list.ida->begin;
    while (list.a != NULL) {
        if (list.ida->size == i) {
            my_putchar('\n');
            return (0);
        }
        if (list.a->nb > list.a->next->nb)
            break;
        list.a = list.a->next;
        i++;
    }
    return (1);
}

void my_str(char *str)
{
    write(1, str, 3);
}

char *my_put_binary_nbr(int nb)
{
    char *nbr = malloc(sizeof(char) * 32);
    int i = 0;

    if (nb < 0) {
        nb = nb * -1;
    }
    while (nb >= 2) {
        if (nb % 2 == 0)
            nbr[i] = '0';
        else
            nbr[i] = '1';
        i++;
        nb = nb / 2;
    }
    nbr[i] = nb + '0';
    return (nbr);
}
