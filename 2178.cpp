#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, ans;
char map[100][100];
bool visited[100][100];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<pair<int,int>, int>> q;

bool safe(int h, int w) {
	return h >= 0 && h < N && w >= 0 && w < M;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	visited[0][0] = true;
	q.push(make_pair(make_pair(0,0), 0));
	while (!q.empty()) {
		pair<pair<int,int>, int> a = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int h = a.first.first + dy[i];
			int w = a.first.second + dx[i];
			int cost = a.second+1;
			if (safe(h, w) && map[h][w] == '1' && !visited[h][w]) {
				if (h == N - 1 && w == M - 1)
					ans = min(ans, cost);
				visited[h][w] = true;
				q.push(make_pair(make_pair(h, w), cost));
			}
		}
	}
	cout << ans+1 << '\n';

	return 0;
}