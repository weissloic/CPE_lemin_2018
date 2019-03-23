/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../include/lem_in.h"
#include "../include/my.h"

void free_node(node_t *node)
{
    node_t *tmp;

    while (node->next != NULL) {
        tmp = node;
        node->neighbor = node->neighbor->next;
        node = node->next;
        free(tmp->name);
        free(tmp->neighbor);
        free(tmp);
    }
    free(node->neighbor);
    free(node);
}

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

char *transform_buff(char *buff)
{
    char *str = malloc(sizeof(char) * (my_strlen(buff) + 1));
    char **tab = my_str_to_word_array(buff);
    int a = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (is_comment(tab[i]) == 1 && is_tunnel(tab[i], 0) == 0) {
            for (int j = 0; tab[i][j] != '#' && tab[i][j] != '\0'; j++) {
                str[a] = tab[i][j];
                a++;
            }
            if (tab[i][0] != '#') {
                str[a] = '\n';
                a++;
            }
        } else if (is_comment(tab[i]) == 2) {
            for (int j = 0; tab[i][j] != '\0'; j++) {
                str[a] = tab[i][j];
                a++;
            }
            str[a] = '\n';
            a++;
        } else if (is_comment(tab[i]) == 0 && is_tunnel(tab[i], 0) == 0) {
            for (int j = 0; tab[i][j] != '\0'; j++) {
                str[a] = tab[i][j];
                a++;
            }
            str[a] = '\n';
            a++;
        }
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (is_tunnel(tab[i], 0) == 1) {
            for (int j = 0; tab[i][j] != '#' && tab[i][j] != '\0'; j++) {
                str[a] = tab[i][j];
                a++;
            }
            str[a] = '\n';
            a++;
        }
    }
    str[a] = '\0';
    return (str);
}

int main(void)
{
    //node_t *node = malloc(sizeof(node_t));
    char *buff = NULL;
    int nbr = 0;
    int error = 0;

    buff = get_file();
    if (buff == NULL || my_strlen(buff) > 20000)
        return (84);
    buff = transform_buff(buff);
    error = gest_error(buff);
    display_data(buff);
    if (error == 84)
        return (84);
    // init_node(node, buff);
    // nbr = count_nodes(buff);
    // for (int i = 0; i < nbr - 1; i++)
    //     create_list(node, buff);
    // connect_nodes(node);
    // if (check_links(node) == 84 || check_pos(node) == 84)
    //     return (84);
    // do_algo(node);
    // free_node(node);
    return (0);
}
