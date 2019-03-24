/*
** EPITECH PROJECT, 2019
** gest_error
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lem_in.h"

int check_valid_room(char *str)
{
    int counter = 0;

    if (str[0] == '#')
        return (0);
    for (int i = 0; str[i + 1] != '\0' && str[i + 1] != '#'; i++) {
        if (str[i] == ' ')
            counter++;
    }
    if (counter != 2)
        return (84);
    return (0);
}

int check_valid_tunnel(char *str)
{
    int counter = 0;

    if (str[0] == '#')
        return (0);
    for (int i = 0; str[i + 1] != '\0' && str[i + 1] != '#'; i++) {
        if (str[i] == '-') {
            if (str[i + 1] == ' ')
                return (84);
            counter++;
        }
    }
    if (counter != 1)
        return (84);
    return (0);
}

int check_two_end_start(char *buffer, char *line)
{
    char **tab = my_str_to_word_array(buffer);
    int counter = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], line) == 0)
            counter++;
    }
    if (counter != 1)
        return (84);
    return (0);
}

int miss_start_or_end(char *buffer, char *line)
{
    char **tab = my_str_to_word_array(buffer);

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], line) == 0)
            return (0);
    }
    return (84);
}

int gest_error(char *buff)
{
    if (first_number(buff) == 84 || miss_start_or_end(buff, "##start") == 84
    || miss_start_or_end(buff, "##end") == 84
    || check_two_end_start(buff, "##start") == 84
    || check_two_end_start(buff, "##end") == 84) {
        return (84);
    }
    return (0);
}