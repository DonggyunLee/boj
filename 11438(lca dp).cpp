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
Vector tree[100001];
int parent[100001][17];
int depth[100001];
bool visited[100001];

inline void _swap(int &a, int &b) {
	int t(a);
	a = b;
	b = t;
}
void prec(int dep, int cur, int par) {
	visited[cur] = true;
	depth[cur] = dep;
	parent[cur][0] = par;
	for (int i = 0; i < tree[cur].size; i++)
		if (!visited[tree[cur].arr[i]])
			prec(dep + 1, tree[cur].arr[i], cur);
}
inline int lca(int a, int b) {
	if (depth[a] < depth[b]) _swap(a, b);
	if(depth[a] != depth[b]) 
		for (int i = 16; i >= 0; i--) 
			if (depth[parent[a][i]] >= depth[b]) 
				a = parent[a][i];
	if (a != b) {
		for (int i = 16; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}
	return a;
}
int main() {
	freopen("input.txt", "r", stdin);
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
	for (int i = 1; i < 17; i++)
		for(int cur=1;cur<=N;cur++)
			parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}

	return 0;
}