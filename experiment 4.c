#include <stdio.h>
int pass = 1;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++) L[i] = arr[left + i];
	for (j = 0; j < n2; j++) R[j] = arr[mid + 1 +j];
	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
			else arr[k++] = R[j++];
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
	printf("Pass: ");
	for (int x = left; x <= right; x++)
		printf("%d ", arr[x]);
	printf("\n");
}

void mergeSort( int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid ,right);
	}
}

int main() {
	int n;
	printf("no of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("elements: ");
	for (int i =0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Given array:\n");
	printArray(arr,n);
	mergeSort( arr, 0, n - 1);
	printf("Sorted array:\n");
	printArray(arr, n);
	return 0;
}
