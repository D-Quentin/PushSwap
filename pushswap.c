/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** m
*/

#include "my.h"

typedef struct node_s node_t;
struct node_s {
    int nb;
    node_t *next;
    node_t *prev;
};

typedef struct identity_s identity_t;
struct identity_s {
    int size;
    node_t *begin;
    node_t *end;
};

typedef struct my_lists {
    node_t *a;
    node_t *b;
    identity_t *ida;
    identity_t *idb;
    int sa;
    int sb;
    int fa;
    char **tab1;
    char **tab2;
} list_t;
/*
typedef struct my_lists {
    int *a;
    int	*b;
    int sa;
    int sb;
    int fa;
    char **tab1;
    char **tab2;
} list_t;
*/
list_t initialization(list_t list, int ac, char **av);
int check_end(list_t list, int ac);
list_t pa(list_t list);
list_t pb(list_t list);
//list_t sb(list_t list);
//list_t sa(list_t list);
list_t rb(list_t list);
list_t ra(list_t list);
list_t rrb(list_t list);
list_t rra(list_t list);
char *my_put_binary_nbr(int nb);

void main(int ac, char** av)
{
    list_t list; 
    int i = 0;
    int j = 0;
    int b = 0;
    int k = 0;
    int n = 0;
    list = initialization(list, ac, av);
    while (i != 32) {
        while (j != list.fa) {
            if (list.tab1[j][i] == '1') {
                list.tab2[k] = list.tab1[j];
                k++;
                //my_put_nbr(list.ida->begin->nb);
                list = pb(list);
                my_putchar(' ');
                list = rb(list);
                my_putchar(' ');
            } else {
                list.tab1[n] = list.tab1[j];
                n++;
                list = ra(list);
                my_putchar(' ');
            }
            j++;
        }
        k = 0;
        while (list.sa != list.fa) {
            list = pa(list);
            my_putchar(' ');
            list = ra(list);
            my_putchar(' ');
            list.tab1[n] = list.tab2[k];
            k++;
            n++;
        }
        k = 0;
        n = 0;
        j = 0;
        i++;
    }
    i = 0;
    while (i != list.fa) {
        list.a = list.ida->begin;
        if (list.a->nb < 0) {
            list = pb(list);
            my_putchar(' ');
            list = rb(list);
            my_putchar(' ');
        } else {
            list = ra(list);
            my_putchar(' ');
        }
        i++;
    }
    while (list.sa != list.fa) {
        list = pa(list);
        my_putchar(' ');
    }
    my_putstr("sb");
    my_putchar('\n');
    /*
    list.a = list.ida->begin;
    i = 0;
    while (i != list.ida->size) {
        my_put_nbr(list.a->nb);
        my_putchar(' ');
        list.a = list.a->next;
        i++;
    }
    my_putchar('\n');
    */
    /*
    while (i != 32) {
        if (check_end(list, ac) == 0)
            break;
        while (j != list.fa) {
            if (list.tab1[j][i] == '1') {
                list.tab2[k] = list.tab1[j];
                k++;
                list = pb(list);
                my_putchar(' ');
                list = rb(list);
                my_putchar(' ');
            } else {
                list.tab1[n] = list.tab1[j];
                n++;
                list = ra(list);
                my_putchar(' ');
            }
            j++;
        }
        k = 0;
        while (list.sa != list.fa) {
            list = pa(list);
            my_putchar(' ');
            list = ra(list);
            my_putchar(' ');
            list.tab1[n] = list.tab2[k];
            k++;
            n++;
        }
        k = 0;
        n = 0;
        j = 0;
        i++;
    }
    i = 0;
    while (i != list.fa) {
        if (list.a[0] < 0) {
            list = pb(list);
        } else {
            list = ra(list);
            my_putchar(' ');
        }
        i++;
    }
    while (list.sa != list.fa) {
        list = rrb(list);
        my_putchar(' ');
        list = pa(list);
        my_putchar(' ');
    }
    my_putstr("sb");
    my_putchar('\n');

    
    i = 0;
    while (i != list.sa) {
        my_put_nbr(list.a[i]);
        my_putchar(' ');
        i++; 
    }
    my_putchar('\n');
    */
    return;  
}
/*
list_t initialization(list_t list, int ac, char **av)
{
    int i = 0;
    
    list.a  = malloc(sizeof(int) * ac);
    list.b  = malloc(sizeof(int) * ac);
    list.sa = ac - 1;
    list.sb = 0;
    list.fa = list.sa;
    while (i != list.sa) {
        list.a[i] = my_getnbr(av[i + 1]);
        i++;
    }
    list.tab1 = malloc(sizeof(char*) * list.fa);
    list.tab2 = malloc(sizeof(char*) * list.fa);
    i = 0;
    while (i != 32) {
        list.tab1[i] = malloc(sizeof(char) * 32);
        list.tab2[i] = malloc(sizeof(char) * 32);
        i++;
    }
    i = 0;
    while (i != list.fa) {
        list.tab1[i] = my_put_binary_nbr(list.a[i]);
        i++;
    }
    return (list);
}
*/

list_t initialization(list_t list, int ac, char **av)
{
    int i = 2;

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

    list.tab1 = malloc(sizeof(char*) * list.fa);
    list.tab2 = malloc(sizeof(char*) * list.fa);
    i = 0;
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
/*
int check_end(list_t list, int ac)
{
    int i = 0;

    if (list.sb != 0)
        return (1);
    list.
    while (i != list.sa - 1) {
        if (list.a[i] > list.a[i + 1] || list.sb != 0) {
            return (1);
        }
        i++;
    }
    return (0);
}
*/
list_t rra(list_t list)
{
    node_t *tmp;

    tmp = list.ida->end;
    list.ida->end = list.ida->end->prev;
    tmp->prev = NULL;
    list.ida->begin->prev = tmp;
    list.ida->begin = tmp;
    
    my_putstr("rra");
    return (list);
}

list_t rrb(list_t list)
{
    node_t *tmp;

    tmp = list.idb->end;
    if (list.sb != 1)
        list.idb->end = list.idb->end->prev;
    else {
        list.idb->end = list.idb->end;
        my_putstr("rrb");
        return (list);
    }
    tmp->prev = NULL;
    list.idb->end->next = NULL;
    list.idb->begin->prev = tmp;
    list.idb->begin = tmp;
    
    my_putstr("rrb");
    return (list);
}

list_t ra(list_t list)
{
    node_t *tmp;
    
    tmp = list.ida->begin;
    if (list.sa != 1)
        list.ida->begin = list.ida->begin->next;
    else {
        my_putstr("ra");
        return (list);
    }
    tmp->next = NULL;
    list.ida->end->next = tmp;
    list.ida->end = tmp;
    my_putstr("ra");
    return (list);
}

list_t rb(list_t list)
{
    node_t *tmp;

    tmp = list.idb->begin;
    if (list.sb != 1)
        list.idb->begin = list.idb->begin->next;
    else {
        my_putstr("rb");
        return (list);
    }
    tmp->next = NULL;
    list.idb->end->next = tmp;
    list.idb->end = tmp;
    
    my_putstr("rb");
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
    my_putstr("pb");
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
    my_putstr("pa");
    return (list);
}

/*
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
    int b = list.b[0];
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
*/
