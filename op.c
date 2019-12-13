/*
** EPITECH PROJECT, 2019
** op
** File description:
** m
*/

#include "my.h"

list_t ra(list_t list)
{
    node_t *tmp;

    tmp = list.ida->begin;
    if (list.sa != 1)
        list.ida->begin = list.ida->begin->next;
    else {
        my_str("ra ");
        return (list);
    }
    tmp->next = NULL;
    list.ida->end->next = tmp;
    list.ida->end = tmp;
    my_str("ra ");
    return (list);
}

list_t rb(list_t list)
{
    node_t *tmp;

    tmp = list.idb->begin;
    if (list.sb != 1)
        list.idb->begin = list.idb->begin->next;
    else {
        my_str("rb ");
        return (list);
    }
    tmp->next = NULL;
    list.idb->end->next = tmp;
    list.idb->end = tmp;

    my_str("rb ");
    return (list);
}

list_t pb(list_t list)
{
    node_t *tmp;

    tmp = list.ida->begin;

    if (list.idb->begin == NULL) {
        list.ida->begin = tmp->next;
        tmp->next = NULL;
        list.idb->begin = tmp;
        list.idb->end = tmp;
    } else {
        list.ida->begin = tmp->next;
        tmp->next = list.idb->begin;
        list.idb->begin = tmp;
    }

    list.sa -= 1;
    list.sb += 1;
    my_str("pb ");
    return (list);
}

list_t pa(list_t list)
{
    node_t *tmp;

    tmp = list.idb->begin;
    if (list.ida->begin == NULL) {
        list.idb->begin = tmp->next;
        tmp->next = NULL;
        list.ida->begin = tmp;
        list.ida->end = tmp;
    } else {
        list.idb->begin = list.idb->begin->next;
        tmp->next = list.ida->begin;
        list.ida->begin = tmp;
    }
    list.sb -= 1;
    list.sa += 1;
    my_str("pa ");
    return (list);
}
