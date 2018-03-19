//#include <stdio.h>
//
//int N;
//
//void swap(int *a, int *b) {
//	int *tmp = a;
//	a = b;
//	b = tmp;
//}
//typedef struct Heap {
//	int size;
//	int arr[100000];
//	Heap():size(0){}
//	void push(int a) {
//		arr[++size] = a;
//		upheap();
//	}
//	void upheap() {
//		int cur = size;
//		while (cur / 2 > 0 && arr[cur] < arr[cur / 2]) {
//			swap(&arr[cur], &arr[cur / 2]);
//			cur >>= 1;
//		}
//	}
//
//};
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
//
//	
//}