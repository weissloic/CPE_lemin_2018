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

void check_two_end_start(char *buffer, node_t *node)
{
    char **tab = my_str_to_word_array(buffer);

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "##end") == 0)
            node->number_end++;
        if (my_strcmp(tab[i], "##start") == 0)
            node->number_start++;
    }
}

int first_number(char *buffer)
{
    char **tab = my_str_to_word_array(buffer);
    int number = 0;
    int i = 1;

    if (tab[0] == NULL)
        return (84);
    number = my_getnbr(tab[0]);
    if (number <= 0)
        return (84);
    for (; tab[i] != NULL; i++) {
        if (check_valid_room(tab[i]) == 84 && check_valid_tunnel(tab[i]) == 84)
            return (84);
    }
    return (0);
}

int wrong_first_line(char *buffer)
{
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
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

int gest_error(char *buff, node_t *node)
{
    check_two_end_start(buff, node);
    if (first_number(buff) == 84 || miss_start_or_end(buff, "##start") == 84
        || miss_start_or_end(buff, "##end") == 84
            || wrong_first_line(buff) == 84 || node->number_end > 1 || node->number_start > 1)
        return (84);
    return (0);
}