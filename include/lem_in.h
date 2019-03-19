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

// MAIN

// DISPLAY_DATA
void display_end(int *);
void display_start(int *);
void display_ants(int);
void display_data(char *);
int print_type(char *);

// GET_LENGTH
int get_length_word_tunnel2(char *, int);
int get_length_word_tunnel(char *, int);
int get_length_word(char *, int);
char *get_tunnel2_in_str(char *, int);
char *get_tunnel_in_str(char *, int *);

// GET_ROOMS
int is_room(char *, int);
char *get_room_in_str(char *, int *);
int get_room_in_nbr(char *, int *);
int get_nbr_rooms(char *);
void get_room(char *, node_t *);

// NODE
int count_nodes(char *);
void connect_nodes(node_t *);
void init_node(node_t *, char *);
void create_list(node_t *, char *);
void display_list(node_t *);

// PARSER
int get_number_of_ants(char *);
int my_get_length(char *, int);
char *my_get_line(char *, int *);
char *my_stradd(char *, char *);
char *get_file(void);

// TUNNEL
int is_tunnel(char *, int);
int tunnel_connected(node_t *, char *);
void add_tunnel(node_t *, char *);
void get_nbr_tunnels(node_t *, char *);

// ALGORITHM
void find_path(node_t *);


#endif /* LEM_IN_H_ */
