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

#ifndef LEM_IN_H_
#define LEM_IN_H_

typedef struct node {
    char *name;
    int nbr_ants;
    int posx;
    int posy;
    int nbr_tunnels;
    int busy;
    struct node *next;
    struct node **neighbor;
} node_t;

typedef struct data_s {
    int nbr_ants;
    int **rooms;
    int **tunnels;
    int *start;
    int *end;
} data_t;

int get_nbr_tunnels(char *buff);
int get_nbr_rooms(char *buff);
int get_number_of_ants(char *buff);
void get_start_end(char *buff, data_t *data);
void get_rooms(char *buff, data_t *data);
void get_tunnels(char *buff, data_t *data);
void display_ants(int ants);
void display_rooms(data_t *data, char *buff);
void display_start(int *start);
void display_end(int *end);
void display_tunnels(data_t *data, char *buff);
int get_room_in_nbr(char *buff, int *i);
char *get_file(void);

#endif /* LEM_IN_H_ */
