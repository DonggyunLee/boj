#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
char map[51][51];

void chkwidth(int h) {
	int count = 1;
	for (int i = 0; i < N - 1; i++) {
		if (map[h][i] == map[h][i + 1]) count++;
		else count = 1;
		ans = max(ans, count);
	}
}
void chkheight(int w) {
	int count = 1;
	for (int i = 0; i < N - 1; i++) {
		if (map[i][w] == map[i + 1][w]) count++;
		else count = 1;
		ans = max(ans, count);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N-1; j++) {
			swap(map[i][j], map[i][j + 1]);
			chkwidth(i);
			chkheight(j);
			chkheight(j + 1);
			swap(map[i][j], map[i][j + 1]);
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++) {
			swap(map[j][i], map[j + 1][i]);
			chkheight(i);
			chkwidth(j);
			chkwidth(j + 1);
			swap(map[j][i], map[j + 1][i]);
		}

	cout << ans << '\n';

	return 0;
}