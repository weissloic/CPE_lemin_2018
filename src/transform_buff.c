/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** transform_buff
*/

#include "../include/lem_in.h"
#include "../include/my.h"

char *do_comment(char *str, char **tab, int *a, int i)
{
    for (int j = 0; tab[i][j] != '#' && tab[i][j] != '\0'; j++) {
        str[a[0]] = tab[i][j];
        a[0]++;
    }
    if (tab[i][0] != '#') {
        str[a[0]] = '\n';
        a[0]++;
    }
    return (str);
}

char *do_start_end(char *str, char **tab, int *a, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        str[a[0]] = tab[i][j];
        a[0]++;
    }
    str[a[0]] = '\n';
    a[0]++;
    return (str);
}

char *do_room(char *str, char **tab, int *a, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        str[a[0]] = tab[i][j];
        a[0]++;
    }
    str[a[0]] = '\n';
    a[0]++;
    return (str);
}

char *do_tunnel(char *str, char ** tab, int *a, int i)
{
    for (int j = 0; tab[i][j] != '#' && tab[i][j] != '\0'; j++) {
        str[a[0]] = tab[i][j];
        a[0]++;
    }
    str[a[0]] = '\n';
    a[0]++;
    return (str);
}

char *transform_buff(char *buff)
{
    char *str = malloc(sizeof(char) * (my_strlen(buff) + 1));
    char **tab = my_str_to_word_array(buff);
    int a = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (is_comment(tab[i]) == 1 && is_tunnel(tab[i], 0) == 0)
            str = do_comment(str, tab, &a, i);
        if (is_comment(tab[i]) == 2)
            str = do_start_end(str, tab, &a, i);
        if (is_comment(tab[i]) == 0 && is_tunnel(tab[i], 0) == 0)
            str = do_room(str, tab, &a, i);
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (is_tunnel(tab[i], 0) == 1)
            str = do_tunnel(str, tab, &a, i);
    }
    str[a] = '\0';
    return (str);
}