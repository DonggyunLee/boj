#include <iostream>
using namespace std;

struct Vector {
	int *arr;
	int *dis;
	int size;
	int vsize;
	Vector() {
		size = 0, vsize = 4;
		arr = new int[vsize];
		dis = new int[vsize];
	}
	void push(int data, int cost) {
		if (size == vsize) {
			int *tmp = new int[vsize];
			int *tmp1 = new int[vsize];
			for (int i = 0; i < vsize; i++) {
				tmp[i] = arr[i];
				tmp1[i] = dis[i];
			}
			delete[] arr;
			delete[] dis;
			arr = new int[vsize << 1];
			dis = new int[vsize << 1];
			for (int i = 0; i < vsize; i++) {
				arr[i] = tmp[i];
				dis[i] = tmp1[i];
			} 
			vsize <<= 1;
			delete[] tmp;
			delete[] tmp1;
		}
		dis[size] = cost;
		arr[size++] = data;
	}
};
int N, M;
Vector tree[40011];
int cost[40011];
int visit[40011];
int depth[40011];
int parent[40011];

void prec(int dep, int cur, int par, int _cost) {
	visit[cur] = true;
	depth[cur] = dep;
	parent[cur] = par;
	cost[cur] = _cost;
	for (int i = 0; i < tree[cur].size; i++) {
		if (!visit[tree[cur].arr[i]]) {
			prec(dep + 1, tree[cur].arr[i], cur, tree[cur].dis[i]);
		}
	}
}
inline void _swap(int &a, int &b) {
	int t(a);
	a = b;
	b = t;
}
int lca(int a, int b) {
	int sum = 0;
	if (depth[a] < depth[b]) _swap(a, b);
	while (depth[a] != depth[b]) {
		sum += cost[a];
		a = parent[a];
	}
	while (a != b) {
		sum += cost[a];
		a = parent[a];
		sum += cost[b];
		b = parent[b];
	}
	return sum;
}
int main() {
	//freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int t1, t2, t3;
	for (int i = 1; i < N; i++) {
		cin >> t1 >> t2 >> t3;
		tree[t1].push(t2, t3);
		tree[t2].push(t1, t3);
	}
	prec(1, 1, 0, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}

	return 0;
}