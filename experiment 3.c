// Type Content here...
#include <stdio.h>
int pass = 1;

void printPass(int arr[], int low, int high) {
	printf("Pass: ");
	for (int i = low; i <= high; i++) {
		printf("%d ",arr[i]);
}
	printf("\n");
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	int temp;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
			temp = arr[i + 1];
			arr[i + 1] = arr[high];
			arr[high] = temp;
	
			printPass(arr,low,high);
			return i+1;
			}
				
void quicksort(int arr[], int low, int high){
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low,pi - 1) ;
		quicksort(arr, pi + 1, high);

	}
}

int main() {
	int n, arr[100];
	printf("number of elements: ");
	scanf("%d", &n);
	printf("elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Original array: ");
	for (int i=0;i<n;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	quicksort(arr,0,n-1);
	printf("Sorted array: ");
	for (int i=0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
