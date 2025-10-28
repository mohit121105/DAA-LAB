#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
	int u, v, w;
};

int find(int parent[], int i) {
	if (parent[i] != i)
		parent[i] = find(parent, parent[i]);
	return parent[i];
}

void union1(int parent[], int rank[], int i, int j) {
	int xroot = find(parent, i);
	int yroot = find(parent, j);

	if (rank[xroot] < rank[yroot]) {
		parent[xroot] = yroot;
	} else if (rank[xroot] > rank[yroot]) {
		parent[yroot] = xroot;
	} else {
		parent[yroot] = xroot;
		rank[xroot]++;
	}
}

void kruskalMST(int **cost, int V) {
	struct Edge edges[V*V];
	int ecount = 0;


	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
		if (cost[i][j] != 9999) {
				edges[ecount].u = i;
				edges[ecount].v = j;
				edges[ecount].w = cost[i][j];
				ecount++;
			}
		}
	}


	for (int i = 0; i < ecount - 1; i++) {
		for (int j = 0; j < ecount - i - 1; j++) {
			 if (edges[j].w > edges[j+1].w) {
				struct Edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}

	int parent[V], rank[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	int e = 0, i = 0, minCost = 0;

	while (e < V-1 && i < ecount) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		i++;

		int set_u = find(parent, u);
		int set_v = find(parent, v);

		if (set_u != set_v) {
			printf("Edge %d:(%d, %d) cost:%d\n", e, u, v, w);
			minCost += w;
			union1(parent, rank, set_u, set_v);
			e++;
		}
	}

	printf("Minimum cost= %d\n", minCost);
}




int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
