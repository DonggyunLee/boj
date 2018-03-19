#include <iostream>
using namespace std;

int fail[1000001];
char T[1000001], P[1000001];
int ans[1000001];
int ansSize;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin.getline(T, sizeof(T));
	cin.getline(P, sizeof(P));
	int nP;
	for (nP = 0; P[nP]; nP++);
	for (int i = 1,j=0; P[i]; i++) {
		while (j && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}
	for (int i = 0, j = 0; T[i]; i++) {
		while (j && T[i] != P[j]) j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == nP - 1) {
				ans[ansSize++] = i - nP + 2;
				j = fail[j];
			}
			else j++;
		}
	}
	cout << ansSize << '\n';
	for (int i = 0; i < ansSize; i++) cout << ans[i] << " ";

	return 0;
}