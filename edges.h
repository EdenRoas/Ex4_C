#ifndef EDGES_
#define EDGES_
#include"nodes.h"
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


edge* create_edge( node* dest, int weight);
void creat_first_e(node** head, int src_id, node* dest, int weight);
void delete_edge(edge** del_e);
void print_list_edges(edge** e);
void remove_edge( edge** head, node* n);


#endif