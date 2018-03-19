#include<iostream>
using namespace std;

int u[1000001], v[1000001], cost[1000001];
int group[100001];

void init() {
	for (int i = 0; i < 1001; i++)
		group[i] = 0;
}
void swap(int *src, int *trg) {
	int *tmp = src;
	src = trg;
	trg = tmp;
}
void qsort(int* u, int *v, int* cost, int left, int right) {
	int l = left, r = right;
	int pivot = cost[(l + r) / 2];
	while (l <= r) {
		while (cost[l] < pivot) l++;
		while (cost[r] > pivot) r--;
		if (l <= r) {
			if (l != r) {
				swap(cost[l], cost[r]);
				swap(u[l], u[r]);
				swap(v[l], v[r]);
			}
			l++, r--;
		}
	}
	if (left < r) qsort(u, v, cost, left, r);
	if (l < right) qsort(u, v, cost, l, right);
}
int find(int a) {
	if (group[a] == a) return a;
	else return group[a] = find(group[a]);
}
int merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	group[x] = y;
	return 1;
}
int main() {
	//freopen("1647input.txt", "r", stdin);
	init();
	int N, M;
	cin >> N;
	cin >> M;
	int minSum = 0;
	for (int i = 0; i < M; i++) {
		cin >> u[i] >> v[i] >> cost[i];
	}
	for (int i = 1; i <= N; i++) group[i] = i;
	qsort(u, v, cost, 0, M - 1);
	int idx = 0;
	for (int i = 0; i < M; i++) {
		if (find(u[i]) == find(v[i])) continue;
		idx+= merge(u[i], v[i]);
		minSum += cost[i];
		if (idx == N - 2) break;
	}
	cout << minSum << endl;

}