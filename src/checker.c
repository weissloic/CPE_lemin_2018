/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** checker
*/

#include "../include/lem_in.h"
#include "../include/my.h"

int is_comment(char *buff)
{
    int hash = 0;

    for (int j = 0; buff[j] != '\0' && buff[j] != '\n'; j++) {
        if (buff[j] == '#')
            hash++;
    }
    if (hash == 2) {
        if (my_strcmp(buff, "##start") == 0 || my_strcmp(buff, "##end") == 0)
            return (2);
        else
            return (3);
    }
    return (hash);
}

int is_tunnel(char *buff, int i)
{
    int counter = 0;

    for (; buff[i + 1] != '\n' && buff[i + 1] != '\0'; i++) {
        if (buff[i - 1] != ' ' && buff[i] == '-' && buff[i + 1] != ' ')
            counter++;
    }
    if (counter == 1)
        return (1);
    return (0);
}

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
    if (check_valid_room(tab[0]) == 0 || check_valid_tunnel(tab[i]) == 0)
        return (84);
    for (; tab[i] != NULL; i++) {
        if (check_valid_room(tab[i]) == 84 &&
        check_valid_tunnel(tab[i]) == 84) {
            return (84);
        }
    }
    return (0);
}

