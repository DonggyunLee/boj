#include <iostream>
using namespace std;

char str[1000001];
int strTable[26];

int _max(int a, int b) {
	return a > b ? a : b;
}
int hashing(char a) {
	if (a >= 'A' && a <= 'Z') {
		return a - 'A';
	}
	else {
		return a - 'a';
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int max = 0;
	for (int i = 0; str[i]; i++) {
		int tmp = hashing(str[i]);
		strTable[tmp]++;
		max = _max(max, strTable[tmp]);
	}
	char ans = 0;
	int size = 0;
	for (int i = 0; i < 26; i++) {
		if (strTable[i] >= max) {
			if (size == 1) {
				cout << "?" << '\n';
				return 0;
			}
			ans = i + 'A';
			size++;
		}
	}
	cout << ans << '\n';

	return 0;
}