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

typedef enum flags {
    BASIC,
    START,
    END
} flags_e;

typedef struct node {
    flags_e flag;
    char *name;
    int nbr_ants;
    int posx;
    int posy;
    int nbr_tunnels;
    int busy;
    struct node *next;
    struct node *neighbor;
} node_t;

void get_nbr_tunnels(node_t *node, char *buff);
int get_nbr_rooms(char *buff);
int get_number_of_ants(char *buff);
char *get_room_in_str(char *buff, int *i);
void get_tunnels(node_t *node, char *buff);
void display_ants(int ants);
void display_start(int *start);
void display_end(int *end);
int get_room_in_nbr(char *buff, int *i);
char *get_file(void);
void get_room(char *buff, node_t *node);
char *get_tunnel_in_str(char *buff, int *i);
char *get_tunnel2_in_str(char *buff, int i);
int get_length_word_tunnel(char *buff, int i);
int get_length_word_tunnel2(char *buff, int i);
char *my_stradd(char *str1, char *str2);

#endif /* LEM_IN_H_ */
