/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** algorithm
*/

#include "../include/lem_in.h"
#include "../include/my.h"

node_t *find_start(node_t *node)
{
    while (node != NULL && node->flag != START)
        node = node->next;
    return (node);
}

node_t *find_end(node_t *node)
{
    while (node != NULL && node->flag != END)
        node = node->next;
    return (node);
}

node_t *go_to_next_neighbor(node_t *node)
{
    if (node->neighbor->next != NULL)
        node = node->neighbor->next->neighbor;
    else
        return (NULL);
    return (node);
}

void move_ant(node_t **node, node_t **next, int ant)
{
    node[0]->busy = 0;
    next[0]->busy = ant;
}

node_t *go_to_prev_neighbor(node_t *node, node_t *tmp)
{
    node_t *prev = find_start(node);
    node_t *next = go_to_next_neighbor(prev);

    if (tmp->flag == START)
        return (tmp);
    while (next != NULL && my_strcmp(next->name, tmp->name) != 0) {
        prev = go_to_next_neighbor(prev);
        next = go_to_next_neighbor(next);
    }
    return (prev);
}

node_t *find_next_to_move(node_t *node, int *backspace)
{
    node_t *tmp = find_end(node);
    node_t *tmp_prev = go_to_prev_neighbor(node, tmp);
    int loop = 1;
    static char *name = "Lucas";

    while (loop == 1) {
        if (tmp_prev->flag == START && node->nbr_ants <= 1) {
            tmp = find_end(node);
            tmp_prev = go_to_prev_neighbor(node, tmp);
            name = my_strdup("Lucas");
        }
        if (((tmp_prev->busy != 0 || tmp_prev->flag == START) && (tmp->busy == 0 || tmp->flag == END)) && my_strcmp(name, tmp_prev->name) != 0) {
            loop = 0;
            if (tmp_prev->flag != START) {
                name = my_strdup(tmp->name);
            }
            else {
                *backspace = 1;
                name = my_strdup("Lucas");
            }
        }
        if (loop == 1) {
            tmp = go_to_prev_neighbor(node, tmp);
            tmp_prev = go_to_prev_neighbor(node, tmp);
        }
    }
    return (tmp_prev);
}

node_t *find_more_on_same_turn(node_t *node, node_t *actual)
{
    node_t *tmp = go_to_prev_neighbor(node, actual);
    node_t *tmp_next = go_to_next_neighbor(tmp);
    node_t *tmp_prev = go_to_prev_neighbor(node, tmp);

    while (tmp->flag != START) {
        if ((tmp->busy != 0 || tmp->flag == START) && (tmp_next->busy == 0 || tmp_next->flag == END))
            return (tmp);
        tmp = go_to_prev_neighbor(node, tmp);
        tmp_next = go_to_prev_neighbor(node, tmp_next);
        tmp_prev = go_to_prev_neighbor(node, tmp_prev);
    }
    return (node);
}

void do_algo(node_t *node)
{
    const int total_ants = node->nbr_ants;
    node_t *tmp = find_start(node);
    node_t *tmp_next = go_to_next_neighbor(tmp);
    int ant = 1;
    int backspace = 0;
    int ok = 1;

    my_printf("#moves\n");
    while (node->nbr_ants > 0) {
        if (ant < total_ants) {
            if (tmp->flag != START) {
                ok = 2;
                tmp = find_more_on_same_turn(node, tmp);
            }
            if (tmp->flag == START) {
                if (ok == 2)
                    my_printf("\n");
                else
                    ok = 1;
                tmp = find_next_to_move(node, &backspace);
            }
            tmp_next = go_to_next_neighbor(tmp);
            if (ant + 1 > total_ants)
                backspace = 0;
        } else {
            tmp_next = find_end(node);
            tmp = go_to_prev_neighbor(node, tmp_next);
            while ((tmp->busy == 0 && tmp->flag != START) || (tmp_next->busy != 0 && tmp_next->flag != END)) {
                tmp = go_to_prev_neighbor(node, tmp);
                tmp_next = go_to_prev_neighbor(node, tmp_next);
            }
            if (tmp_next->flag == END) {
                if (ok == 2)
                    my_printf("\n");
                ok++;
                backspace = 0;
            } else
                my_printf(" ");
        }
        if (tmp_next == NULL) {
            tmp_next = find_end(node);
            tmp = go_to_prev_neighbor(node, tmp_next);
        }
        if (tmp_next->flag == END) {
            node->nbr_ants--;
        }
        if (tmp->flag == START) {
            move_ant(&tmp, &tmp_next, ant);
            ant++;
        } else
            move_ant(&tmp, &tmp_next, tmp->busy);
        my_printf("P%d-%s", tmp_next->busy, tmp_next->name);
        if (backspace == 1) {
            my_printf("\n");
        } else if (ant < total_ants)
            my_printf(" ");
        backspace = 0;
    }
    my_printf("\n");
}