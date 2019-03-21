/*
** EPITECH PROJECT, 2023
** Lem_in
** File description:
** Created by benjaminkuhnel,
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include "../include/get_next_line.h"

int is_tunnel(char *buff, int i)
{
    int counter = 0;

    for (; buff[i] != '\n' && buff[i] != '\0'; i++) {
        if (buff[i] == '-')
            counter++;
    }
    if (counter == 1)
        return (1);
    return (0);
}

int tunnel_connected(node_t *node, char *str)
{
    node_t *tmp = node->neighbor;

    if (tmp == NULL)
        return (0);
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, str) == 0) {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void add_tunnel(node_t *node, char *str)
{
    node_t *tmp = node->neighbor;
    int turn = 0;

    while (tmp->next != NULL) {
        turn++;
        tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(node_t));
    tmp->next->name = NULL;
    tmp->next->name = my_stradd(tmp->next->name, str);
    tmp->next->next = NULL;
}

void get_nbr_tunnels(node_t *node, char *buff)
{
    int i = 0;
    char *str = NULL;
    char *str2 = NULL;

    while (buff[i + 1] != '\0') {
        while (is_tunnel(buff, i) == 0) {
            for (; buff[i] != '\n' && buff[i] != '\0'; i++);
            i++;
        }
        str = get_tunnel_in_str(buff, &i);
        str2 = get_tunnel2_in_str(buff, i);
        if (my_strcmp(str, node->name) == 0 &&
            tunnel_connected(node, str2) == 0) {
            node->nbr_tunnels++;
            add_tunnel(node, str2);
        }
        i++;
    }
}