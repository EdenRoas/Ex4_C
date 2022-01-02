#ifndef NODES_
#define NODES_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int priority;
    int visited;
} node, *pnode;


node* create_node(int index) ;
void creat_first(node** head, int index);
void update_node(node* n , node**head);
void add(node** head, int index);
void delete_node(node**head);
void print_list_nodes(node*head);
void remove_node(node**head, int index);

#endif
