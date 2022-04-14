#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(float *a, float *b);
void heapify(float arr[], int n, int i);
void heapSort(float arr[], int n);

int main() {
	srand((unsigned)time(NULL));
	float data[20] = {0};
	for(int i = 0; i < 20; i++){ //임의로 20개의 실수형 데이터 받기  (0 ~ 100)
		data[i] = (float)((rand() % 10000) / (float)100);
	}
	printf("Before sort\n");
	for(int i = 0; i < 20; i++) {
		printf("%.2f ", data[i]); //이쁘게 소수점 두자리 까지만 보여주기
	}
	int n = sizeof(data) / sizeof(data[0]);
	heapSort(data, n);
	printf("\nSorted array is \n");
	for(int i = 0; i < 20; i++) {
		printf("%.2f ", data[i]); //이쁘게 소수점 두자리 까지만 보여주기
	}
}

// Function to swap the the position of two elements
void swap(float *a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(float *data, int n, int i) { // Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && data[left] > data[largest])
		largest = left;
	if (right < n && data[right] > data[largest])
		largest = right;
	if (largest != i) {
		printf("swap %d and %d\n", i, largest);
		swap(&data[i], &data[largest]);
		heapify(data, n, largest);
	}
}

// Main function to do heap sort
void heapSort(float *data, int n) { 
	// Build max heap
	printf("\nBuild max heap\n");
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(data, n, i);
	printf("Done building max heap\n");
	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		printf("\npop data index %d\n\n", i);
		swap(&data[0], &data[i]);
		heapify(data, i, 0);
	}
}