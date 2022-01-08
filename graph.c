#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "edges.h"


node* create_node(int index) {
    node* new_node = (node *) malloc(sizeof(node));
    if (new_node) {
        new_node->node_num = index;
        new_node->edges = NULL;
        new_node->next = NULL;
        return new_node;
    }
    exit(1);
}

void insert_node_cmd(node** head, pnode node)  //insert a node to the list
{
    if(node == NULL){
        printf("no memory!");
        return;
    }
    if(*head == NULL)
    {
        *head = node;
        return;
    }
    pnode temp = *head;
    while(temp->next) 
    {
        temp = temp->next;
    }
    temp->next = node;
}

void delete_node_cmd(pnode* head, pnode node){ //delete the node node
    if(*head == NULL)
        return;
    if((*head)->node_num == node->node_num){
        pnode temp = *head;
        *head = (*head)->next;
        pedge edge_temp = temp ->edges;
        while(edge_temp){ //cuts the edges from the deleted node
            pedge remove_edges = edge_temp;
            edge_temp = edge_temp -> next;
            free(remove_edges);
        }
        temp ->edges = NULL;
        pnode temp2 = temp;
        temp = temp->next;
        pnode temp_endpoint = *head;
        while(temp_endpoint){
            remove_edge(&(temp_endpoint->edges), node->node_num);
            temp_endpoint = temp_endpoint -> next;
        }
        free(temp2); // now we can delete the node
        if(!*head){
            *head = NULL;
        }
        return;
    }
    pnode temp = *head;
    while(temp->next && temp->next->node_num != node->node_num)
        temp = temp->next;
    if(!temp->next){
        return;
    }
    //free edges
    pedge edge_tmp = temp->next->edges;
    while(edge_tmp){
        pedge remove_edges = edge_tmp;
        edge_tmp = edge_tmp -> next;
        free(remove_edges);
    }
    temp -> next -> edges = NULL;
    //remove node
    pnode temp2 = temp -> next;
    temp -> next = temp -> next -> next;
    pnode temp_endpoint = *head;
    while(temp_endpoint){
        remove_edge(&(temp_endpoint->edges), node->node_num);
        temp_endpoint = temp_endpoint -> next;
    }
    free(temp2);
    return;
}

void printGraph_cmd(pnode head){ //for us
    while(head){
        printf("%d (", head -> node_num);
        print_list(head -> edges);
        printf(") -> ");
        head = head->next;
    }
    printf("||\n");
}

void deleteGraph_cmd(pnode* head){
    while(*head){
        delete_node_cmd(head, *head);
    }
}