//#include <iostream>
//using namespace std;
//
//struct Vector {
//	int *arr;
//	int size;
//	int vsize;
//	int *cost;
//	Vector() {
//		size = 0, vsize = 4;
//		arr = new int[vsize];
//		cost = new int[vsize];
//	}
//	void push(int data, int co) {
//		if (size == vsize) {
//			int *tmp = new int[vsize];
//			int *tmp1 = new int[vsize];
//			for (int i = 0; i < vsize; i++) {
//				tmp[i] = arr[i];
//				tmp1[i] = cost[i];
//			}
//			delete[] arr;
//			delete[] cost;
//			arr = new int[vsize << 1];
//			cost = new int[vsize << 1];
//			for (int i = 0; i < vsize; i++){
//				arr[i] = tmp[i];
//				cost[i] = tmp1[i];
//			}
//			vsize <<= 1;
//		}
//		cost[size] = co;
//		arr[size++] = data;
//	}
//};
//
//int N, M;
//Vector tree[100001];
//int parent[100001][17];
//int cost[100001][17];
//int depth[100001];
//bool visited[100001];
//int minAns, maxAns;
//
//inline void _swap(int &a, int &b) {
//	int t(a);
//	a = b;
//	b = t;
//}
//void prec(int dep, int cur, int par, int co) {
//	visited[cur] = true;
//	depth[cur] = dep;
//	parent[cur][0] = par;
//	cost[cur][0] = co;
//	for (int i = 0; i < tree[cur].size; i++)
//		if (!visited[tree[cur].arr[i]])
//			prec(dep + 1, tree[cur].arr[i], cur, tree[cur].cost[i]);
//}
//inline int _max(int a, int b) {
//	return a > b ? a : b;
//}
//inline int _min(int a, int b) {
//	return a < b ? a : b;
//}
//inline void lca(int a, int b) {
//	if (depth[a] < depth[b]) _swap(a, b);
//	int max=_max(cost[a][0], cost[b][0]), min=_min(cost[a][0],cost[b][0]);
//	if (depth[a] != depth[b])
//		for (int i = 16; i >= 0; i--)
//			if (parent[a][i]!=0 && depth[parent[a][i]] >= depth[b]) {
//				a = parent[a][i];
//				max = _max(max, cost[a][i]);
//				min = _min(min, cost[a][i]);
//			}
//	if (a != b) {
//		for (int i = 16; i >= 0; i--) {
//			if (parent[a][i]!=0 && parent[b][i]!=0 && parent[a][i] != parent[b][i]) {
//				a = parent[a][i];
//				b = parent[b][i];
//				max = _max(max, cost[a][i]);
//				min = _min(min, cost[a][i]);
//				max = _max(max, cost[b][i]);
//				min = _min(min, cost[b][i]);
//			}
//		}
//		if (parent[a][0] != 0) {
//			a = parent[a][0];
//			max = _max(max, cost[a][0]);
//			min = _min(min, cost[a][0]);
//		}
//		if (parent[b][0] != 0) {
//			b = parent[b][0];
//			max = _max(max, cost[b][0]);
//			min = _min(min, cost[b][0]);
//		}
//	}
//	maxAns = max, minAns = min;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> N;
//	int t1, t2, t3;
//	for (int i = 1; i < N; i++) {
//		cin >> t1 >> t2 >> t3;
//		tree[t1].push(t2, t3);
//		tree[t2].push(t1, t3);
//	}
//	prec(1, 1, 0, 0);
//	for (int i = 1; i < 17; i++)
//		for (int cur = 1; cur <= N; cur++) {
//			parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
//			cost[cur][i] = cost[cost[cur][i - 1]][i - 1];
//		}
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> t1 >> t2;
//		lca(t1, t2);
//		cout << minAns << " " << maxAns << '\n';
//	}
//
//	return 0;
//}