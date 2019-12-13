/*
** EPITECH PROJECT, 2019
** initialization
** File description:
** m
*/

#include "my.h"

list_t initialization(list_t list, int ac, char **av)
{
    list.sa = ac - 1;
    list.sb = 0;
    list.fa = list.sa;
    list.a = malloc(sizeof(node_t));
    list.b = malloc(sizeof(node_t));
    list.ida = malloc(sizeof(identity_t));
    list.idb = malloc(sizeof(identity_t));
    list.ida->size = 1;
    list.ida->begin = list.a;
    list.ida->end = list.a;
    list.a->nb = my_getnbr(av[1]);
    list.a->prev = NULL;
    list.idb->size = 1;
    list.idb->begin = NULL;
    list.idb->end = NULL;
    list.b->prev = NULL;
    list.b->next = NULL;
    return (list);
}
list_t initialization3(list_t list, int ac, char **av)
{
    int i = 0;

    list.tab1 = malloc(sizeof(char*) * list.fa);
    list.tab2 = malloc(sizeof(char*) * list.fa);
    while (i != 32) {
        list.tab1[i] = malloc(sizeof(char) * 32);
        list.tab2[i] = malloc(sizeof(char) * 32);
        i++;
    }
    i = 0;
    list.a = list.ida->begin;
    while (i != list.fa) {
        list.tab1[i] = my_put_binary_nbr(list.a->nb);
        list.a = list.a->next;
        i++;
    }
    return (list);
}

list_t initialization2(list_t list, int ac, char **av)
{
    int i = 2;

    while (i != list.fa + 1) {
        list.a->next = malloc(sizeof(node_t));
        list.b->next = malloc(sizeof(node_t));
        list.a->next->prev = list.a;
        list.b->next->prev = list.b;
        list.b = list.b->next;
        list.a = list.a->next;
        list.b->next = NULL;
        list.a->nb = my_getnbr(av[i]);
        list.ida->size += 1;
        i++;
    }
    list.a->next = NULL;
    list.b->next = NULL;
    list.ida->end = list.a;
    return (list);
}
