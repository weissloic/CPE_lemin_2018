/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** get_rooms
*/

#include "my.h"

int get_length_word(char buff[], int i)
{
    int length = 0;

    for (; buff[i] != ' '; i++)
        length++;
    return (length);
}

int get_room_in_nbr(char buff[], int *i)
{
    int length = get_length_word(buff, *i);
    char *nbr_str = malloc(sizeof(char) * length);
    int a = 0;

    for (; buff[i[0]] != ' ' && buff[i[0]] != '\n' &&
    buff[i[0]] != '-'; i[0]++) {
        nbr_str[a] = buff[i[0]];
        a++;
    }
    i[0]++;
    return (my_getnbr(nbr_str));
}

int get_nbr_rooms(char buff[])
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

void get_rooms_loop(char buff[], int i, data_t *data)
{
    int not_a_room = 0;
    int line = 0;

    while (buff[i] != '\0') {
        for (; buff[i] != '\n' && buff[i] != '\0'; i++);
        i++;
        if (not_a_room > 0)
            not_a_room--;
        if (buff[i] == '#' && buff[i + 1] == '#' &&
        (buff[i + 2] == 's' || buff[i + 2] == 'e'))
            not_a_room = 2;
        if (buff[i] >= 48 && buff[i] <= 57 &&
        buff[i + 1] != '-' && not_a_room == 0) {
            data->rooms[line][0] = get_room_in_nbr(buff, &i);
            data->rooms[line][1] = get_room_in_nbr(buff, &i);
            data->rooms[line][2] = get_room_in_nbr(buff, &i);
            i--;
            line++;
        }
    }
}

void get_rooms(char buff[], data_t *data)
{
    int i = 0;
    data->rooms = malloc(sizeof(int *) * get_nbr_rooms(buff));

    for (int a = 0; a < get_nbr_rooms(buff); a++)
        data->rooms[a] = malloc(sizeof(int) * 3);
    get_rooms_loop(buff, i, data);
}