/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** my
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

typedef struct link_node {
    int dest;
    struct link_node *next;
} link_node_t;

typedef struct link {
    struct link_node *head;
} link_t;

typedef struct graph {
    int length;
    struct link *array;
} graph_t;

typedef struct data_s {
    int nbr_ants;
    int **rooms;
    int **tunnels;
    int *start;
    int *end;
} data_t;

int my_getnbr(char *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);

#endif /* !MY_H_ */
