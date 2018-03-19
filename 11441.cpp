#include <stdio.h>

int N, M;
int arr[100001];
int sum[100001];

int main() {
	freopen("11441input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
	}
	scanf("%d", &M);
	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", sum[e] - sum[s - 1]);
	}

	return 0;
}