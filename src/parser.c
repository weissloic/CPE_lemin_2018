/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parser
*/

#include "../include/my.h"
#include "../include/lem_in.h"
#include "../include/get_next_line.h"

int get_number_of_ants(char *buff)
{
    int i = 0;
    char *nbr_str;
    int nbr = 0;

    for (; buff[i] != '\n'; i++);
    nbr_str = malloc(sizeof(char) * (i + 1));
    for (int a = 0; a < i; a++)
        nbr_str[a] = buff[a];
    nbr_str[i] = '\0';
    nbr = my_getnbr(nbr_str);
    return (nbr);
}

int my_get_length(char *buff, int i)
{
    int length = 0;

    for (; buff[i] != '\n' && buff[i] != '\0'; i++)
        length++;
    return (length);
}

char *my_get_line(char *buff, int *i)
{
    char *str = malloc(sizeof(char) * (my_get_length(buff, *i) + 1));
    int a = 0;

    for (; buff[i[0]] != '\n' && buff[i[0]] != '\0'; i[0]++) {
        str[a] = buff[i[0]];
        a++;
    }
    str[a] = '\0';
    i[0]++;
    return (str);
}

char *my_stradd(char *str1, char *str2)
{
    int length1 = 0;
    int length2 = 0;
    char *result = NULL;
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
    result[a] = '\0';
    return (result);
}

char *get_file(void)
{
    char *str = get_next_line(0);
    char *str_to_add;

    if (str == NULL)
        return (NULL);
    str_to_add = get_next_line(0);
    if (str_to_add == NULL)
        return (NULL);
    while (str_to_add != NULL) {
        str = my_stradd(str, "\n");
        str = my_stradd(str, str_to_add);
        str_to_add = get_next_line(0);
    }
    if (str == NULL)
        return (NULL);
    str = my_stradd(str, "\n");
    return (str);
}