#include <stdio.h>
#include <stdlib.h>

// Function to Sort the files in ascending order, perform optimal file merging and return the minimum cost
int optimalMerge(int files[], int n) {
	int cost = 0;

	while (n > 1) {
		int min1 = -1, min2 = -1;

		for (int i = 0; i < n; i++) {
			if (min1 == -1 || files[i] < files[min1]) {
				min2 = min1;
				min1 = i;
			} else if (min2 == -1 || files[i] < files[min2]) {
				min2 = i;
			}
		}

		int merged = files[min1] + files[min2];
		cost += merged;

		files[min1] = merged;

		for (int i = min2; i < n - 1; i++) {
			files[i] = files[i + 1];
		}
		n--;
	}

	return cost;
}

int main() {
    int n;
    printf("Number of files: ");
    scanf("%d", &n);
    int *files = (int *)malloc(n * sizeof(int));
    printf("Enter the sizes of %d files: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d\n", minCost);
    free(files);
    return 0;
}
