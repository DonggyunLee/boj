#include <iostream>
using namespace std;

int N, P;
int st[7][300001];
int stsize[7];
int ans;

void push(int line, int data) {
	st[line][stsize[line]++] = data;
	ans++;
}
void pop(int line) {
	if (stsize[line] == 0) return;
	st[line][--stsize[line]] = 0;
	ans++;
}
int back(int line) {
	if (stsize[line] == 0) return -1;
	return st[line][stsize[line] - 1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> P;
	int line, num;
	for (int i = 0; i < N; i++) {
		cin >> line >> num;
		while (back(line) > num) pop(line);
		if (back(line) == num) continue;
		push(line, num);
	}
	cout << ans << '\n';
	
	return 0;
}