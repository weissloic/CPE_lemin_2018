/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** display_data
*/

#include "../include/my.h"
#include "../include/lem_in.h"

void display_data(char *buff)
{
    int i = 0;
    char *str;
    int type = 0;

    my_printf("#number_of_ants\n%s\n", my_get_line(buff, &i));
    my_printf("#rooms\n");
    while (buff[i] != '\0' && type <= 0) {
        str = my_get_line(buff, &i);
        type = print_type(str);
        if (type == 0)
            my_printf("%s\n", str);
    }
}

int print_type(char *str)
{
    static int ok = 0;

    if (str[0] == '#' && str[1] == '#') {
        if (str[2] == 's' || str[2] == 'e')
            my_printf("%s\n", str);
        return (-1);
    }
    if (is_tunnel(str, 0) == 1 && ok == 0) {
        ok = 1;
        my_printf("#tunnels\n");
    }
    return (0);
}