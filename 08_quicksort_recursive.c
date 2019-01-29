// Nikhil M Tomy
// S3D
// 37

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int array[], int low, int high) {
  int i = low-1;
  int pivot = array[high];

  for (int j=low; j<high; j++) {
    if (array[j]<pivot) {
      swap(&array[++i], &array[j]);
    }
  }
  swap(&array[++i], &array[high]);
  return i;
}
void quickSort(int array[], int low, int high) {
	int partitionIndex;
	if (low < high) {
		partitionIndex = partition(array, low, high);
		quickSort(array, low, partitionIndex-1);
		quickSort(array, partitionIndex+1, high);
	}
}
int printArray(int a[], int size) {
	int i=0;
	for (i=0; i<size; i++) {
		printf("%d\n", a[i]);
	}
}
int main() {
	int array[100], i, size;
	printf("Enter size of the array : ");
	scanf("%d", &size);
	printf("Enter array elements\n");
	for (i=0; i<size; i++)
		scanf("%d", &array[i]);
	printf("Sorted Array\n");
	quickSort(array, 0, size-1);
	printArray(array, size);
}
