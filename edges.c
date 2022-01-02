#include <stdio.h>
#include "graph.h"
#include "nodes.h"

edge *creat_edge(node *dest, int weight)
{
    edge *new_edge = (edge *)malloc(sizeof(edge));
    if (!new_edge)
    {
        return NULL;
    }
    new_edge->weight = weight;
    new_edge->endpoint = dest;
    new_edge->next = NULL;
    return new_edge;
}

void creat_first_e(node **head, int src_id, node *dest, int weight)
{
    if (!head)
    { //if the graph is empty
        return;
    }
    node *head_copy = *head;
    while (head_copy)
    {
        if (head_copy->node_num == src_id)
        {
            edge *e = create_edge(dest, weight);
            if (!e)
            {
                printf("Not enough memory!");
                return;
            }
            edge *tmp = head_copy->edges;
            e->next = tmp;
            head_copy->edges = e;
            return;
        }
        head_copy = head_copy->next;
    }
}

void delete_edge(edge **del_e)
{
    if (!(*del_e))
    {
        return;
    }
    if (!(*del_e)->next)
    {
        // *H=NULL;
        free(del_e);
    }
    else
    {
        while ((*del_e)->next != NULL)
        {
            edge *tmp = *del_e;
            *del_e = (*del_e)->next;
            free(tmp);
        }
        edge *tmp = *del_e;
        *del_e = (*del_e)->next;
        tmp = NULL;
        free(tmp);
        del_e = NULL;
        free(del_e);
    }
}
void print_list_edges(edge **e)
{
    while (*e)
    {
        if ((*e)->next != NULL)
        {
            printf(" n-%d, w-%d -> ", (*e)->endpoint->node_num, (*e)->weight);
            (*e) = (*e)->next;
        }
        else
        {
            printf("n-%d, w-%d ", (*e)->endpoint->node_num, (*e)->weight);
            (*e) = (*e)->next;
        }
    }
}
void remove_edge(edge **head, node *n)
{
    if (!*head)
    {
        return;
    }
    if ((*head)->endpoint->node_num == n->node_num)
    { //if we want to delete the first edge
        edge *temp = *head;
        *head = (*head)->next;
        temp->endpoint = NULL;
        temp->next = NULL;
        free(temp);
        //printf("deletd the first edge\n");
    }
    else
    {
        edge *temp = *head;
        while (temp->next && (temp->next)->endpoint != n->node_num)
        {
            temp = temp->next;
        }
        if (!temp->next)
        {
            return;
        }
        edge *temp2 = temp->next;
        temp->next = temp->next->next;
        temp = NULL;
        free(temp2);
    }
}
