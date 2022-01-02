#include <stdio.h>
#include <string.h>
#include "algo.h"

int main() {
    pnode head = NULL;
    char option;
    scanf("%c",option);
    while(option == 'A' || option == 'B' || option == 'D' || option == 'S' || option == 'T') {
        if(option == 'A') { 
            deleteGraph_cmd(&head); 
            head = NULL; 
            build_graph_cmd(&head);
        }
        else if(option == 'B') {
            insert_node_cmd(&head);
        }
        else if(option == 'D') { 
            delete_node_cmd(&head);
        }
        else if(option == 'S') { 
            shortsPath_cmd(head);
        }
        else if(option == 'T') { 
            TSP_cmd(head);
        }
        option = getchar(); 
    }
    deleteGraph_cmd(&head);//necessary? 
    return 0;
}