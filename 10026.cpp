#include <iostream>
#include <queue>
using namespace std;

struct Pair {
	int x,y;
	Pair():x(0),y(0){}
};
int N, tc;
char map[100][100];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[100][100];

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < N;
}
void bfs(int h, int w, char type) {
	Pair a;
	queue<Pair> q;
	visited[h][w]++;
	a.y = h, a.x = w;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = a.y + dy[i];
			int wi = a.x + dx[i];
			if (safe(he, wi) && map[he][wi] == type && visited[he][wi] == tc) {
				Pair b;
				b.y = he, b.x = wi;
				q.push(b);
				visited[he][wi]++;
			}
		}
	}
}
void _bfs(int h, int w) {
	Pair a;
	queue<Pair> q;
	visited[h][w]++;
	a.y = h, a.x = w;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = a.y + dy[i];
			int wi = a.x + dx[i];
			if (safe(he, wi) && map[he][wi] != 'B' && visited[he][wi]==tc) {
				Pair b;
				b.y = he, b.x = wi;
				q.push(b);
				visited[he][wi]++;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans1=0, ans2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) {
				bfs(i, j, map[i][j]);
				ans1++;
			}
	tc++;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if (visited[i][j] == tc) {
				if (map[i][j] == 'B') {
					bfs(i, j, map[i][j]);
					ans2++;
				}
				else {
					_bfs(i, j);
					ans2++;
				}
			}
	cout << ans1 << " " << ans2 << '\n';

	return 0;
}