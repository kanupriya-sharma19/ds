#include <stdio.h>
#include <stdlib.h> 

struct node {
    int vertex;
    struct node *next;
};

void displayGraph(struct node *adj[], int no_of_nodes);
void deleteGraph(struct node *adj[], int no_of_nodes);
void createGraph(struct node *adj[], int no_of_nodes);

int main() {
    struct node *Adj[10];
    int i, no_of_nodes;

    printf("\nEnter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);

    for (i = 0; i < no_of_nodes; i++) {
        Adj[i] = NULL;
    }

    createGraph(Adj, no_of_nodes);
    printf("\nThe graph is: ");
    displayGraph(Adj, no_of_nodes);
    deleteGraph(Adj, no_of_nodes);

    return 0;
}

void createGraph(struct node *Adj[], int no_of_nodes) {
    struct node *new_node, *last;
    int i, j, n, val;

    for (i = 0; i < no_of_nodes; i++) {
        last = NULL;
        printf("\nEnter the number of neighbours of %d: ", i);
        scanf("%d", &n);

        for (j = 1; j <= n; j++) {
            printf("\nEnter the neighbour %d of %d: ", j, i);
            scanf("%d", &val);

            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->vertex = val;
            new_node->next = NULL;

            if (Adj[i] == NULL) {
                Adj[i] = new_node;
            } else {
                last->next = new_node;
            }
            last = new_node;
        }
    }
}

void displayGraph(struct node *Adj[], int no_of_nodes) {
    struct node *ptr;
    int i;

    for (i = 0; i < no_of_nodes; i++) {
        ptr = Adj[i];
        printf("\nThe neighbours of node %d are:", i);
        while (ptr != NULL) {
            printf("\t%d", ptr->vertex);
            ptr = ptr->next;
        }
    }
}

void deleteGraph(struct node *Adj[], int no_of_nodes) {
    int i;
    struct node *temp, *ptr;

    for (i = 0; i < no_of_nodes; i++) {
        ptr = Adj[i];
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        Adj[i] = NULL;
    }
}
