#include <stdio.h>
#include <stdlib.h>
#include "graph.c"
#include "edges.c"
#include "algo.c"

int main()
{
    node *graph = NULL;
    int ot = getchar();
    int numOfNodes, i, index, dest, weight;
    int madeit;
    int first = 0;
    char n;
    while (65 <= ot && ot <= 90)
    {
        switch (ot)
        {
        case 'A':
            if (graph != NULL)
            {
                deleteGraph_cmd(&graph);
            }
            getchar();
            scanf("%d", &numOfNodes);
            scanf("%c", &n);
            scanf("%c", &n);
            i = 0;
            for (i = 0; i < numOfNodes; i++)
            {
                scanf("%d", &index);
                if (i == 0)
                {
                    graph = create_node(index);
                }
                pnode current_node = graph;
                while (current_node)
                {
                    if (current_node->node_num == index)
                    {
                        break;
                    }
                    current_node = current_node->next;
                }

                if (!current_node)
                {
                    current_node = create_node(index);
                    insert_node_cmd(&graph, current_node);
                }
                madeit = scanf("%d", &dest);
                while (madeit)
                {
                    scanf("%d", &weight);
                    pnode tmp = graph;
                    while (tmp)
                    {
                        if (tmp->node_num == dest)
                        {
                            break;
                        }
                        tmp = tmp->next;
                    }
                    // if so
                    if (tmp)
                    {
                        pnode node_dst = tmp;
                        add(&current_node->edges, node_dst, weight);
                    }
                    else
                    {
                        pnode node_dst = create_node(dest);
                        insert_node_cmd(&graph, node_dst);
                        add(&current_node->edges, node_dst, weight);
                    }
                    if (getchar() == ' ')
                    {
                        madeit = scanf("%d", &dest);
                    }
                    else
                    {
                        break;
                    }
                }
                ot = getc(stdin);
                if (ot != 'n')
                {
                    break;
                }
            }
            break;
        case 'B':

            ot = getchar();
            int index;
            scanf("%d", &index);

            pnode current_node = graph;
            while (current_node)
            {
                if (current_node->node_num == index)
                {
                    break;
                }
                current_node = current_node->next;
            }
            if (!current_node)
            {
                current_node = create_node(index);
                insert_node_cmd(&graph, current_node);
            }
            pedge edge_tmp = current_node->edges;
            while (edge_tmp)
            {
                pedge remove_edges = edge_tmp;
                edge_tmp = edge_tmp->next;
                free(remove_edges);
            }
            current_node->edges = NULL;

            int destN;
            int weight;
            scanf("%d", &destN);
            scanf("%d", &weight);

            while (ot == 32)
            {
                pnode dest_node = graph;
                while (dest_node)
                {
                    if (dest_node->node_num == destN)
                    {
                        break;
                    }
                    dest_node = dest_node->next;
                }
                if (!dest_node)
                {
                    dest_node = create_node(destN);
                    insert_node_cmd(&graph, dest_node);
                }

                add(&current_node->edges, dest_node, weight);

                scanf("%d", &destN);
                scanf("%d", &weight);
                ot = getchar();
            }
            break;
        case 'D':
            getchar();
            int node;
            scanf("%d", &node);
            pnode n = create_node(node);
            delete_node_cmd(&graph, n);
            free(n);
            getchar();
            ot = getchar();
            break;
        case 'S':
            getchar();
            int src, dest, short_path;
            scanf("%d", &src);
            scanf("%d", &dest);
            short_path = ShortestPath(&graph, src, dest);
            if (first == 0)
            {
                printf("Dijsktra shortest path: %d \n", short_path);
                first = 1;
            }
            else
            {
                printf("Dijsktra shortest path: %d \n", short_path);
            }
            getchar();
            ot = getchar();
            break;
        case 'T':
        {
            getchar();
            int tsp;
            tsp = TSP(&graph);
            if (first == 0)
            {
                printf("TSP shortest path: %d \n", tsp);
                first = 1;
            }
            else
            {
                printf("TSP shortest path: %d \n", tsp);
            }
            getchar();
            ot = getchar();
            break;
        }
        default:
            break;
        }
    }

    deleteGraph_cmd(&graph);
    return 0;
}