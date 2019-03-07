/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** parser
*/

#include "my.h"

int get_number_of_ants(char buff[])
{
    int i = 0;
    char *nbr_str;
    int nbr = 0;

    for (; buff[i] != '\n'; i++);
    nbr_str = malloc(sizeof(char) * i);
    for (int a = 0; a < i; a++)
        nbr_str[a] = buff[a];
    nbr = my_getnbr(nbr_str);
    return (nbr);
}

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

    for (; buff[i[0]] != ' ' && buff[i[0]] != '\n'; i[0]++) {
        nbr_str[a] = buff[i[0]];
        a++;
    }
    i[0]++;
    return (my_getnbr(nbr_str));
}

void get_start_end_rooms(char buff[], data_t *data)
{
    int i = 0;
    data->start = malloc(sizeof(int) * 3);
    data->end = malloc(sizeof(int) * 3);

    for (; buff[i] != '#' || buff[i + 1] != '#' || buff[i + 2] != 's'; i++);
    for (; buff[i] != '\n'; i++);
    i++;
    data->start[0] = get_room_in_nbr(buff, &i);
    data->start[1] = get_room_in_nbr(buff, &i);
    data->start[2] = get_room_in_nbr(buff, &i);
    for (; buff[i] != '#' || buff[i + 1] != '#' || buff[i + 2] != 'e'; i++);
    for (; buff[i] != '\n'; i++);
    i++;
    data->end[0] = get_room_in_nbr(buff, &i);
    data->end[1] = get_room_in_nbr(buff, &i);
    data->end[2] = get_room_in_nbr(buff, &i);
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));
    int fd = 0;
    char buff[150];
    int size = read(fd, buff, sizeof(buff));

    if (size <= 5)
        return (84);
    data->nbr_ants = get_number_of_ants(buff);
    get_start_end_rooms(buff, data);
    my_putstr("#number_of_ants\n");
    my_put_nbr(data->nbr_ants);
    my_putchar('\n');
    my_putstr("#rooms\n");
    // ...
    my_putstr("##start\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(data->start[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
    my_putstr("##end\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(data->end[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
    my_putstr("#tunnels\n");
    // ...
    my_putstr("#moves\n");
    // ...
    close(fd);
    return (0);
}   