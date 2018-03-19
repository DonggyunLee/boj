#include <iostream>
using namespace std;
#define N 12
#define M 6

char map[N][M];
int ans, checkCnt;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) map[i][j] = 0;
	ans = checkCnt = 0;
}
inline bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
bool check(int height, int width, char type, bool visited[][M]) {
	if (checkCnt == 3) {
		return true;
	}
	visited[height][width] = true;
	for (int i = 0; i < 4; i++) {
		bool isFinish = false;
		int h = height + dy[i];
		int w = width + dx[i];
		if (safe(h, w) && map[h][w] == type&&!visited[h][w]) {
			checkCnt++;
			isFinish = check(h, w, type, visited);
		}
		if (isFinish) return true;
	}
	return false;
}
void del(int height, int width, char type) {
	map[height][width] = '.';
	for (int i = 0; i < 4; i++) {
		int h = height + dy[i];
		int w = width + dx[i];
		if (safe(h, w) && map[h][w] == type)
			del(h, w, type);
	}
}
void drop() {
	for (int width = 0; width < M; width++) {
		for (int height = N-1; height >= 0; height--) {
			if (map[height][width] == '.') {
				int idx = height;
				for (int i = height - 1; i >= 0; i--) {
					if (map[i][width] != '.') {
						map[idx--][width] = map[i][width];
						map[i][width] = '.';
					}
				}
			}
		}
	}
}
int main() {
	freopen("11559input.txt", "r", stdin);
	init();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	while (1) {
		bool isFinish = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] != '.') {
					bool visited[N][M] = { 0, };
					checkCnt = 0;
					if (check(i, j, map[i][j], visited)) {
						isFinish = false;
						del(i, j, map[i][j]);
					}
				}
		if (isFinish) break;
		drop();
		ans++;
	}
	cout << ans << endl;
	return 0;
}