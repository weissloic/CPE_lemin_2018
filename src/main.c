/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../include/my.h"
#include "../include/lem_in.h"

void init_node(node_t *node, char *buff)
{
    node->busy = 0;
    node->flag = BASIC;
    get_room(buff, node);
    node->nbr_tunnels = 0;
    node->nbr_ants = get_number_of_ants(buff);
    node->neighbor = NULL;
    get_nbr_tunnels(node, buff);
    //stock_neighbors(node, buff);
    node->next = NULL;
}

int is_room(char *buff, int i)
{
    int counter = 0;

    for (; buff[i] != '\n' && buff[i] != '\0' &&
        buff[i + 1] != '#'; i++) {
        if (buff[i] == ' ')
            counter++;
    }
    if (counter == 2)
        return (1);
    return (0);
}

void get_room(char *buff, node_t *node)
{
    static int i = 0;

    while (is_room(buff, i) == 0) {
        if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 's')
            node->flag = START;
        if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == 'e')
            node->flag = END;
        for (int i = 0; buff[i] != '\n'; i++);
        i++;
    }
    node->name = get_room_in_str(buff, &i);
    node->posx = get_room_in_nbr(buff, &i);
    node->posy = get_room_in_nbr(buff, &i);
}

int count_nodes(char *buff)
{
    int i = 0;
    int counter = 0;
    int nbr_room = 0;

    while (buff[i] != '\0') {
        for (int j = i; buff[j] != '\n' && buff[j] != '\0' &&
        buff[j + 1] != '#'; j++) {
            if (buff[j] == ' ')
                counter++;
            i = j;
        }
        i++;
        if (counter == 2)
            nbr_room++;
        counter = 0;
    }
    return (nbr_room);
}

void create_list(node_t *node, char *buff)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *tmp = node;

    while (tmp->next != NULL)
        tmp = tmp->next;
    init_node(new_node, buff);
    tmp->next = new_node;
    node = tmp;
}

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
    node_t *new_node = malloc(sizeof(node_t));
    node_t *tmp = node->neighbor;

    if (tmp == NULL) {
        tmp = new_node;
        tmp->name = my_stradd(tmp->name, str);
        node->neighbor = tmp;
        node->neighbor->next = NULL;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
        tmp->next->name = my_stradd(tmp->next->name, str);
        node->neighbor = tmp;
        node->neighbor->next = NULL;
    }
}

void get_nbr_tunnels(node_t *node, char *buff)
{
    int i = 0;
    char *str;
    char *str2;

    while (buff[i + 1] != '\0') {
        while (is_tunnel(buff, i) == 0) {
            for (int i = 0; buff[i] != '\n'; i++);
            i++;
        }
        str = get_tunnel_in_str(buff, &i);
        str2 = get_tunnel2_in_str(buff, i);
        if (my_strcmp(str, node->name) == 0 && tunnel_connected(node, str2) == 0) {
            node->nbr_tunnels++;
            add_tunnel(node, str2);
        }
        i++;
    }
}

void display_list(node_t *node)
{
    node_t *node_display = node;

    while (node_display != NULL) {
        printf("busy: %d\n", node_display->busy);
        printf("name: %s\n", node_display->name);
        printf("flag: %d\n", node_display->flag);
        printf("nbr tunnels: %d\n", node_display->nbr_tunnels);
        if (node_display->nbr_tunnels != 0)
            printf("name neighbors: %s\n", node_display->neighbor->name);
        printf("posx: %d\n", node_display->posx);
        printf("posy: %d\n", node_display->posy);
        node_display = node_display->next;
        printf("\n\n");
    }
}

int main(void)
{
    node_t *node = malloc(sizeof(node_t));
    char *buff;
    int nbr = 0;

    buff = get_file();
    init_node(node, buff);
    nbr = count_nodes(buff);
    for (int i = 0; i < nbr - 1; i++)
        create_list(node, buff);
    //node->nbr_ants = get_number_of_ants(buff);
    display_list(node);
    // get_start_end(buff, data);
    // get_rooms(buff, data);
    // get_tunnels(buff, data);
    // display_ants(data->nbr_ants);
    // display_rooms(data, buff);
    // display_start(data->start);
    // display_end(data->end);
    // display_tunnels(data, buff);
    // my_putstr("#moves\n");
    return (0);
}