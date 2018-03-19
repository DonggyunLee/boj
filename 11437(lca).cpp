#include <iostream>
using namespace std;

struct Vector {
	int *arr;
	int size;
	int vsize;
	Vector() {
		size = 0, vsize = 4;
		arr = new int[vsize];
	}
	void push(int data) {
		if (size == vsize) {
			int *tmp = new int[vsize];
			for (int i = 0; i < vsize; i++) tmp[i] = arr[i];
			delete[] arr;
			arr = new int[vsize << 1];
			for (int i = 0; i < vsize; i++) arr[i] = tmp[i];
			vsize <<= 1;
		}
		arr[size++] = data;
	}
};

int N, M;
Vector tree[50001];
int parent[50001];
int depth[50001];
bool visited[50001];

void prec(int dep, int cur, int par) {
	visited[cur] = true;
	depth[cur] = dep;
	parent[cur] = par;
	for (int i = 0; i < tree[cur].size; i++) {
		if (!visited[tree[cur].arr[i]]) {
			prec(dep+1, tree[cur].arr[i], cur);
		}
	}
}
inline void _swap(int &a, int &b) {
	int t(a);
	a = b;
	b = t;
}
inline int lca(int a, int b) {
	if (depth[a] < depth[b]) _swap(a, b);
	while (depth[a] != depth[b]) a = parent[a];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int main() {
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int t1, t2;
	for (int i = 1; i < N; i++) {
		cin >> t1 >> t2;
		tree[t1].push(t2);
		tree[t2].push(t1);
	}
	prec(1, 1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}

	return 0;
}