#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 100

int minKey(int key[], bool mstSet[], int vertices) {
	int min = INT_MAX, idx = -1;
	for(int v = 0; v < vertices; v++) {
		if (!mstSet[v] && key[v] < min) {
			min = key[v];
			idx = v;
		}
		
	

	}
	return idx;

}
void printTree(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int graph[V][V], int vertices) {
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < vertices; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}
	key[0] = 0;
	for (int count = 0; count < vertices - 1; count++) {
		int u = minKey(key, mstSet, vertices);
		if (u == -1) break;
		mstSet[u] = true;
		for (int v = 0; v < vertices; v++) {
			int w = graph[u][v];
			if (w > 0 && !mstSet[v] && w < key[v]) {
				parent[v] = u;
				key[v] = w;
			}
		}
	}
	printTree(parent, graph, vertices);
	
	
	
	
	
	
	
	
}

int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}
