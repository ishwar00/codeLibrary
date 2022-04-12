
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int Na ,int b[], int Nb ,int c[], int Nc) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < Na && j < Nb) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}
	while (i < Na) {
		c[k++] = a[i++];
	}
	while (j < Nb) {
		c[k++] = b[j++];
	}
}

void merge_sort(int A[], int n) {
	if (n < 2) return;
	int mid = n / 2;
	int left[mid];
	int right[n - mid];
	for (int i = 0; i < mid; ++i) {
		left[i] = A[i];
	}
	for (int i = mid; i < n; ++i) {
		right[i - mid] = A[i];
	}
	merge_sort(left, mid);
	merge_sort(right ,n - mid);
	merge(left ,mid ,right, n-mid ,A ,n);
}
		


int main() {
	int t ,n;
	scanf("%d" ,&t);
	while (t--) {
		int n;
		scanf("%d" ,&n);
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d" ,&a[i]);
		}
		merge_sort(a, n);
		int count = 1;
		int ptr = a[0];
		for (int i = 0; i < n; i++) {
			if(a[i] != ptr){
				count++;
				ptr = a[i];
			}
		}
		if(!a[0]){
			count--;
		}
		printf("%d\n" ,count);
	}
}