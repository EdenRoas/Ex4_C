#include <stdio.h>
//# include <stdlib.h>
#include "graph.h"

node *creat_node(int index)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        return NULL;
    }
    new_node->node_num = index;
    new_node->edges = NULL;
    new_node->next = NULL;
    return new_node;
}

void creat_first(node **head, int index)
{
    node *node = creat_node;
    if (!node)
    {
        printf("Not enough memory!");
    }
    node->node_num = index;
    node->next = *head;
    *head = node;
}
void update_node(node *n, node **head)
{
    edge *e = n->edges;
    edge *temp = n->edges;
    while (!temp)
    {
        int temp_node = temp->endpoint->node_num;
        pnode n = temp->endpoint;
        node *tmph = *head;
        while (tmph->node_num != temp_node)
        {
            tmph++;
        }
        temp++;
    }
}
void add(node **head, int index)
{
    if (*head)
    {
        node *temp = *head;
        while (temp)
        {
            if (temp->node_num == index)
            {
                change_node(temp, head);
                return;
            }
            temp = temp->next;
        }
        add_first(head, index);
    }
}
void delete_node(node **head)
{
    if (!head)
    {
        return;
    }
    if (!(*head)->next)
    {
        *head = NULL;
        free(*head);
    }
    else
    {
        while ((*head)->next != NULL)
        {
            node *temp = *head;
            *head = (*head)->next;
            edge *edge = temp->edges;
            delete_edge(&edge);
            free(temp);
        }
        node *temp = *head;
        *head = (*head)->next;
        edge *edge = temp->edges;
        delete_edge(&edge);
        temp = NULL;
        free(temp);
        head = NULL;
        free(head);
    }
}
void print_list_nodes(node *head)
{
    while (head)
    {
        if (head->next != NULL)
        {
            printf("%d ", head->node_num);
            if (head->edges != NULL)
            {
                printf("edges: ");
                edge *edge = head->edges;
                print_liste(&edge);
            }
            printf(" => ");
            printf("\n");
            head = head->next;
        }
        else
        {
            printf("%d ", head->node_num);
            if (head->edges != NULL)
            {
                printf("edges:");
                edge *edge = head->edges;
                print_liste(&edge);
            }
            head = head->next;
        }
    }
    printf("||\n");
}
void remove_node(node **head, int index)
{
    node *head_copy = *head;
    if (!head)
        return;

    if ((*head)->node_num == index)
    {
        node *temp = *head;
        edge *e = temp->edges;
        delete_edge(&e);

        while (head_copy)
        {
            if (head_copy != temp)
            {
                edge *e1 = head_copy->edges;
                remove_edge(&e1, temp);
            }
        }
        head_copy = head_copy->next;

        *head = (*head)->next;
        temp = NULL;
        free(temp);
        return;
    }
    node *temp = *head;
    while (temp->next && temp->next->node_num != index)
    {
        temp = temp->next;
    }
    if (!temp->next)
    {
        return;
    }
    node *temp2 = temp->next;
    while (head_copy)
    {
        if (head_copy != temp2)
        {
            edge *e1 = head_copy->edges;
            remove_edge(&e1, temp2);
            break;
        }
    }
    head_copy = head_copy->next;
    temp->next = temp->next->next;
    edge *e = temp2->edges;
    deletee(&e);
    free(temp2);
}

