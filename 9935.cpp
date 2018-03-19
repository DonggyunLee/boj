#include <iostream>
using namespace std;

typedef struct Stack {
	int size;
	char st[1000001];
	Stack() : size(0) {
		for (int i = 0; i < 1000001; i++) st[i] = 0;
	}
	void push(char a) {
		st[size++] = a;
	}
	void pop() {
		if (size == 0) return;
		st[--size] = 0;
	}
	void clear() {
		for (int i = 0; i < size; i++) st[i] = 0;
		size = 0;
	}
};
char str[1000001], bomb[38];
int nS, nB;
Stack ans;

int _strlen(char *a) {
	int i;
	for(i=0;a[i]!=0;i++){}
	return i;
}
int main() {
	freopen("9935input.txt", "r", stdin);
	//freopen("o", "w", stdout);
	cin >> str;
	cin >> bomb;
	nS = _strlen(str);
	nB = _strlen(bomb);
	int idx = 0;
	for (int i = 0; i < nS; i++) {
		ans.push(str[i]);
		int n = nB-1;
		if (str[i] == bomb[n]) {
			bool f = false;
			int idx = ans.size - nB;
			for (int j = ans.size - 1; j >= idx; j--, n--) {
				if (ans.st[j] == bomb[n])
					f = true;
				else {
					f = false;
					break;
				}
			}
			if (f) 
				for (int j = 0; j < nB; j++) ans.pop();
		}
	}
	if (ans.size == 0) cout << "FRULA" << endl;
	else cout << ans.st << endl;

	return 0;
}