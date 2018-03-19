#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans;
char str[50][16];
int len[50], bit[50];

void dfs(int depth, int chk, int start, int learned) {
	if (depth >= K || chk==0) {
		int count = 0;
		for (int i = 0; i < N; i++) 
			if ((bit[i] & learned) == bit[i]) count++;
		ans = max(ans, count);
		return;
	}
	for (int i = start; i < 26; i++) {
		if (chk & 1<<i) {
			chk &= ~(1 << i);
			dfs(depth + 1, chk, i+1, learned | (1<<i));
			dfs(depth, chk, i+1, learned);
			break;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (len[i] = 0; str[i][len[i]]; len[i]++);
	}
	int chk = 0, learn = 532741;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < len[i]; j++)
			if(str[i][j]!='a' && str[i][j]!='n' && str[i][j]!='t' && str[i][j]!='i' && str[i][j]!='c')
				bit[i] |= 1 << (str[i][j] - 'a');
		chk |= bit[i];
		bit[i] |= learn;
	}
	K -= 5;
	if (K < 0) cout << "0" << '\n';
	else {
		dfs(0, chk, 0, learn);
		cout << ans << '\n';
	}

	return 0;
}