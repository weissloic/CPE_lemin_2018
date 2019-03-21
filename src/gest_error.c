/*
** EPITECH PROJECT, 2019
** gest_error
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lem_in.h"



int first_number(char *buffer)
{
    char **tab = my_str_to_word_array(buffer);
    int number = my_getnbr(tab[0]);

    if (number <= 0)
        return (84);

    return (0);
}

int wrong_first_line(char *buffer)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] == ' ')
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
            || wrong_first_line(buff) == 84)
        return (84);
    return (0);
}