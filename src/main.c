/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../include/lem_in.h"
#include "../include/my.h"

int main(void)
{
    char *buff = NULL;
    int error = 0;

    buff = get_file();
    buff = my_stradd(buff, "\n");
    if (buff == NULL || my_strlen(buff) > 20000)
        return (84);
    buff = transform_buff(buff);
    error = gest_error(buff);
    display_data(buff);
    if (error == 84)
        return (84);
    return (0);
}
