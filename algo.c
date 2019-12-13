/*
** EPITECH PROJECT, 2019
** algo
** File description:
** m
*/

#include "my.h"

list_t part1_algo(list_t list)
{
    int j = 0;
    int k = 0;

    while (j != list.fa) {
        if (list.tab1[j][list.i] == '1') {
            list.tab2[k] = list.tab1[j];
            k++;
            list = pb(list);
            list = rb(list);
        } else {
            list.tab1[list.n] = list.tab1[j];
            list.n++;
            list = ra(list);
        }
        j++;
    }
    return (list);
}

list_t part2_algo(list_t list)
{
    int k = 0;

    while (list.sa != list.fa) {
        list = pa(list);
        list = ra(list);
        list.tab1[list.n] = list.tab2[k];
        k++;
        list.n++;
    }
    list.i++;
    return (list);
}

list_t part3_algo(list_t list)
{
    int k = 0;

    while (k != list.fa) {
        list.a = list.ida->begin;
        if (list.a->nb < 0) {
            list = pb(list);
            list = rb(list);
        } else {
            list = ra(list);
        }
        k++;
    }
    while (list.sa != list.fa) {
        list = pa(list);
    }
    my_str("sb\n");
}
