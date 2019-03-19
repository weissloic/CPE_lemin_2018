/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** get_rooms
*/

#include "../include/my.h"
#include "../include/lem_in.h"

int is_room(char *buff, int i)
{
    int counter = 0;

    for (; buff[i] != '\n' && buff[i] != '\0' && buff[i + 1] != '#'; i++) {
        if (buff[i] == ' ')
            counter++;
    }
    if (counter == 2)
        return (1);
    return (0);
}

char *get_room_in_str(char *buff, int *i)
{
    int length = get_length_word(buff, *i);
    char *nbr_str = malloc(sizeof(char) * length);
    int a = 0;

    for (; buff[i[0]] != ' ' && buff[i[0]] != '\n'; i[0]++) {
        nbr_str[a] = buff[i[0]];
        a++;
    }
    i[0]++;
    return (nbr_str);
}

int get_room_in_nbr(char *buff, int *i)
{
    int length = get_length_word(buff, *i);
    char *nbr_str = malloc(sizeof(char) * length);
    int a = 0;

    for (; buff[i[0]] != ' ' && buff[i[0]] != '\n'; i[0]++) {
        nbr_str[a] = buff[i[0]];
        a++;
    }
    i[0]++;
    return (my_getnbr(nbr_str));
}

int get_nbr_rooms(char *buff)
{
    int nbr = 0;
    int i = 0;
    int not_a_room = 0;

    while (buff[i] != '\0') {
        for (; buff[i] != '\n' && buff[i] != '\0'; i++);
        i++;
        if (not_a_room > 0)
            not_a_room--;
        if (buff[i] == '#' && buff[i + 1] == '#' &&
        (buff[i + 2] == 's' || buff[i + 2] == 'e'))
            not_a_room = 2;
        if (buff[i] >= 48 && buff[i] <= 57 &&
        buff[i + 1] != '-' && not_a_room == 0)
            nbr++;
    }
    return (nbr);
}

void get_room(char *buff, node_t *node)
{
    static int i = 0;

    while (is_room(buff, i) == 0) {
        if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 's')
            node->flag = START;
        if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 'e')
            node->flag = END;
        for (; buff[i] != '\n'; i++);
        i++;
    }
    node->name = get_room_in_str(buff, &i);
    node->posx = get_room_in_nbr(buff, &i);
    node->posy = get_room_in_nbr(buff, &i);
}