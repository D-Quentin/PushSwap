/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** m
*/

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
    int n;
    int i;
    char **tab1;
    char **tab2;
} list_t;

list_t initialization(list_t list, int ac, char **av);
list_t initialization2(list_t list, int ac, char **av);
list_t initialization3(list_t list, int ac, char **av);
int check_end(list_t list, int ac);
list_t pa(list_t list);
list_t pb(list_t list);
list_t rb(list_t list);
list_t ra(list_t list);
char *my_put_binary_nbr(int nb);
void my_str(char *str);
int check_sorted(list_t list);
list_t part1_algo(list_t list);
list_t part2_algo(list_t list);
list_t part3_algo(list_t list);
