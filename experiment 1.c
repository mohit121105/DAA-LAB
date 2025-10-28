#include <stdio.h>
void read1(int a[], int n) {
		printf("Enter %d elements : ",n);
		for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}
int linearSearch(int a[], int index, int n, int key) {
	if (index > n){ 
		return -1;
	}
	if (a[index] == key){ 
		return index;
	}
	return linearSearch(a,index+1,n,key);
}

