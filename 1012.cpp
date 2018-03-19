#include <iostream>
using namespace std;

int N, M, K, ans;
int map[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) map[i][j] = 0;
	ans = 0;
}
inline bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
void dfs(int height, int width) {
	map[height][width] = 0;
	for (int i = 0; i < 4; i++) {
		int h = height + dy[i];
		int w = width + dx[i];
		if (safe(h, w) && map[h][w] == 1) {
			dfs(h, w);
		}
	}
}
int main() {
	freopen("1012input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		init();
		cin >> M >> N >> K;
		int tx, ty;
		for (int i = 0; i < K; i++) {
			cin >> tx >> ty;
			map[ty][tx] = 1;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
		cout << ans << endl;

	}
	return 0;
}