/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** display_data
*/

#include "../include/my.h"
#include "../include/lem_in.h"

void display_end(int *end)
{
    my_putstr("##end\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(end[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}

void display_start(int *start)
{
    my_putstr("##start\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(start[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}

void display_ants(int ants)
{
    my_putstr("#number_of_ants\n");
    my_put_nbr(ants);
    my_putchar('\n');
}

void display_data(char *buff)
{
    int i = 0;
    char *str;
    int type = 0;

    printf("#number_of_ants\n%s\n", my_get_line(buff, &i));
    printf("#rooms\n");
    while (buff[i] != '\0' && type <= 0) {
        str = my_get_line(buff, &i);
        type = print_type(str);
        if (type == 0)
            printf("%s\n", str);
    }
}

int print_type(char *str)
{
    static int ok = 0;

    if (str[0] == '#' && str[1] == '#') {
        if (str[2] == 's' || str[2] == 'e')
            printf("%s\n", str);
        return (-1);
    }
    if (str[0] != ' ' && str[1] == '-' && str[2] != ' ' && ok == 0) {
        ok = 1;
        printf("#tunnels\n");
    }
    return (0);
}