#include <stdlib.h>
#include <stdio.h>
#include "edges.h"
#include "graph.h"

edge *create_edge(pnode node, int weight)
{
    edge *new_edge = (edge *)malloc(sizeof(edge));
    if (new_edge)
    {
        new_edge->weight = weight;
        new_edge->endpoint = node;
        new_edge->next = NULL;
    }
    return new_edge;
}
void add(edge **head, pnode node, int data)
{
    edge *new_edge = create_edge(node, data);
    if (new_edge == NULL)
    {
        printf("no memory!");
        return;
    }
    if (!*head)
    {
        *head = new_edge;
        return;
    }
    edge *tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_edge;
}

void delete (edge **head)
{
    while (*head)
    {
        edge *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void print_list(edge *head)
{
    while (head)
    {
        printf("%d -> ", head->endpoint->node_num);
        head = head->next;
    }
    printf("|");
}

void remove_edge(edge **head, int dest)
{
    if (*head == NULL)
        return;
    if ((*head)->endpoint->node_num == dest)
    {
        edge *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    edge *tmp = *head;
    if (!tmp)
    {
        return;
    }
    while (tmp->next && tmp->next->endpoint->node_num != dest)
        tmp = tmp->next;
    if (tmp->next == NULL)
        return;
    edge *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}