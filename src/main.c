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

int is_comment(char *buff, int i)
{
    int hash = 0;
    int j = i;

    for (; buff[j] != '\0' && buff[j] != '\n'; j++) {
        if (buff[j] == '#')
            hash++;
    }
    return (hash);
}

char *transform_buff(char *buff)
{
    char *str = malloc(sizeof(char) * (my_strlen(buff) + 1));
    int a = 0;

    str[0] = buff[0];
    a++;
    for (int i = 1; buff[i + 1] != '\0'; i++) {
        if (is_comment(buff, i) == 1) {
            if (buff[i] != '#' && is_tunnel(buff, i) == 0) {
                for (; buff[i + 1] != '#' && buff[i + 1] != '\0'; i++) {
                    str[a] = buff[i];
                    a++;
                }
                if (str[a - 1] != '\n') {
                    str[a] = '\n';
                    a++;
                }
            }
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++);
        } else if (is_comment(buff, i) == 2) {
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++) {
                str[a] = buff[i];
                a++;
            }
            str[a] = '\n';
            a++;
        }
        else if (is_tunnel(buff, i) == 1) {
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++);
            if (str[a] != '\n' && str[a - 1] != '\n') {
                str[a] = '\n';
                a++;
            }
        } else {
            if (str[a] != '\n' || buff[i] != '\n') {
                str[a] = buff[i];
                a++;
            }
        }
    }
    if (str[a - 1] < '0' && str[a - 1] > '9')
        str[a - 1] = '\n';
    else if (str[a - 1] != '\n') {
        str[a] = '\n';
        a++;
    }
    for (int i = 1; buff[i + 1] != '\0'; i++) {
        if (is_comment(buff, i) == 1) {
            if (buff[i] != '#' && is_tunnel(buff, i) == 1) {
                for (; buff[i] != '#' && buff[i + 1] != '\0'; i++) {
                    str[a] = buff[i];
                    a++;
                }
                if (str[a - 1] != '\n') {
                    str[a] = '\n';
                    a++;
                }
            }
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++);
        }
        else if (is_tunnel(buff, i) == 1) {
            if (buff[i] == '\n') {
                str[a] = buff[i];
                a++;
            }
            for (; buff[i - 1] != '\n'; i--);
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++) {
                str[a] = buff[i];
                a++;
            }
            if (buff[i] == '\n') {
                str[a] = buff[i];
                a++;
            }
        } else
            for (; buff[i] != '\n' && buff[i + 1] != '\0'; i++); 
    }
    if (str[a - 1] < '0' && str[a - 1] > '9')
        str[a - 1] = '\n';
    else if (str[a - 1] != '\n') {
        str[a] = '\n';
        a++;
    }
    str[a] = '\0';
    return (str);
}

int main(void)
{
    node_t *node = malloc(sizeof(node_t));
    char *buff = NULL;
    int nbr = 0;

    buff = get_file();
    if (buff == NULL || gest_error(buff) == 84)
        return (84);
    buff = transform_buff(buff);
    display_data(buff);
    init_node(node, buff);
    nbr = count_nodes(buff);
    for (int i = 0; i < nbr - 1; i++)
        create_list(node, buff);
    connect_nodes(node);
    if (check_links(node) == 84 || check_pos(node) == 84)
        return (84);
    //do_algo(node);
    //free_node(node);
    return (0);
}
