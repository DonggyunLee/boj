//#include<iostream>
//using namespace std;
//
//int x[200001], y[200001];
//void _qsort(int *inputY, int* inputX, int left, int right) {
//	int l = left, r = right;
//	int pivot = inputY[(left + right) / 2];
//	int pivot1 = inputX[(left + right) / 2];
//	while (l <= r) {
//		while (1) {
//			if (inputY[l] < pivot) l++;
//			else if (inputY[l] == pivot) {
//				if (inputX[l] < pivot1) l++;
//				else break;
//			}
//			else break;
//		}
//		while (1) {
//			if (inputY[r] > pivot)r--;
//			else if (inputY[r] == pivot) {
//				if (inputX[r] > pivot1) r--;
//				else break;
//			}
//			else break;
//		}
//		if (l <= r) {
//			if (inputY[l] != inputY[r]) {
//				swap(inputY[l], inputY[r]);
//				swap(inputX[l], inputX[r]);
//			}
//			else if (inputY[l] == inputY[r]) {
//				if (inputX[l] > inputX[r]) {
//					swap(inputY[l], inputY[r]);
//					swap(inputX[l], inputX[r]);
//				}
//			}
//			l++; r--;
//		}
//	}
//	if (left < r) _qsort(inputY,inputX, left, r);
//	if (l < right) _qsort(inputY,inputX, l, right);
//}
//int main() {
//	freopen("11651input.txt", "r", stdin);
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) scanf("%d %d", &x[i], &y[i]);
//	_qsort(y, x, 0, N - 1);
//	for (int i = 0; i < N; i++) printf("%d %d\n", x[i], y[i]);
//
//}