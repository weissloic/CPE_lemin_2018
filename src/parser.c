/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parser
*/

#include "include/my.h"
#include "include/lem_in.h"
#include "include/get_next_line.h"

int get_number_of_ants(char *buff)
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

void get_start_end(char *buff, data_t *data)
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

// char *my_getstr(char *str)
// {
//     int a = 0;
//     char *str2;

//     for (; str[a] != '\0' && str[a] != ' '; a++);
//     str2 = malloc(sizeof(char) * a);

// }

// char *get_name_start(void)
// {
//     // char *str = get_next_line(0);

//     // // while (my_strcmp(str, "##start") != 0 && str != NULL)
//     // //     str = my_strdup(str, get_next_line(0));
//     // //str = get_next_line(0);
//     // printf("%s\n", str);
// }

char *my_stradd(char *str1, char *str2)
{
    int length1;
    int length2;
    char *result;
    int a = 0;

    if (str2 == NULL)
        return (str1);
    if (str1 == NULL)
        return (str2);
    length1 = my_strlen(str1);
    length2 = my_strlen(str2);
    result = malloc(sizeof(char) * (length1 + length2 + 1));
    if (result == NULL)
        return (NULL);
    for (int i = 0; str1[i] != 0; i++)
        result[a++] = str1[i];
    for (int i = 0; str2[i] != 0; i++)
        result[a++] = str2[i];
    result[a] = 0;
    return (result);
}

char *get_file(void)
{
    char *str = get_next_line(0);
    char *str_to_add = get_next_line(0);

    while (str_to_add != NULL) {
        str = my_stradd(str, "\n");
        str = my_stradd(str, str_to_add);
        str_to_add = get_next_line(0);
    }
    str = my_stradd(str, "\n");
    return (str);
}

int get_nbr_tunnels(char buff[])
{
    int nbr = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '-')
            nbr++;
    }
    return (nbr);
}

void get_tunnels(char buff[], data_t *data)
{
    int line = 0;

    data->tunnels = malloc(sizeof(int *) * get_nbr_tunnels(buff));
    for (int a = 0; a < get_nbr_tunnels(buff); a++)
        data->tunnels[a] = malloc(sizeof(int) * 2);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '-') {
            i--;
            data->tunnels[line][0] = get_room_in_nbr(buff, &i);
            data->tunnels[line][1] = get_room_in_nbr(buff, &i);
            line++;
        }
    }
}