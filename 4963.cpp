#include <iostream>
using namespace std;

int N, M, ans;
int map[50][50];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init() {
	for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) map[i][j] = 0;
	ans = 0;
}
inline bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
void dfs(int height, int width) {
	map[height][width] = 0;
	for (int i = 0; i < 8; i++) {
		int h = height + dy[i];
		int w = width + dx[i];
		if (safe(h, w) && map[h][w] == 1) {
			dfs(h, w);
		}
	}
}
int main() {
	freopen("4963input.txt", "r", stdin);
	while (1) {
		init();
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		int tx, ty;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];
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