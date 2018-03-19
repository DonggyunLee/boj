#include<iostream>
using namespace std;

int u[100001], v[100001], cost[100001];
int group[1001];

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
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	group[x] = y;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	cin >> M;
	int minSum = 0;
	for (int i = 0; i < M; i++) {
		cin >> u[i] >> v[i] >> cost[i];
	}
	for (int i = 1; i <= N; i++) group[i] = i;
	qsort(u, v, cost, 0, M - 1);
	for (int i = 0; i < M; i++) {
		if (find(u[i]) == find(v[i])) continue;
		merge(u[i], v[i]);
		minSum += cost[i];
	}
	cout << minSum << '\n';
}