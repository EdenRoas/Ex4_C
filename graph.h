#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;



//node 
node* create_node(int index) ;
void creat_first(node** head, int index);
void update_node(node* n , node**head);
void add(node** head, int index);
// void deleten(node**);
// void print_list(node*);
// void remove_node(node**, int);

//edge
edge* create_edge( node* dest, int weight);
void creat_first_e(node** head, int src_id, node* dest, int weight);
void delete_edge(edge** del_e);
void print_list_edges(edge** e);
void remove_edge( edge** head, node* n);



void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif