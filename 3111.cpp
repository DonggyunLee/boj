#include <iostream>
using namespace std;

typedef struct Stack {
	int size;
	char *st;
	Stack() : size(0) {
		st = new char[300001];
	}
	void push(char a) {
		st[size++] = a;
	}
	void pop() {
		if (size == 0) return;
		st[--size] = 0;
	}
};
char A[26], T[300001];
Stack st1, st2, ans;

inline int _strlen(char *a) {
	register int i;
	for (i = 0; a[i] != 0; i++);
	return i;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A;
	cin >> T;
	int n = _strlen(A);
	int N = _strlen(T);
	
	int k=N-1;
	for (int i = 0; i <= k; i++) {
		st1.push(T[i]);
		if (T[i] == A[n - 1]) {
			bool find = true;
			int end = st1.size - n;
			if (end < 0) continue;
			int idx = n - 1;
			for (int j = st1.size -1; j >=end; j--, idx--)
				if (st1.st[j] != A[idx]) {
					find = false;
					break;
				}
			if (find) {
				for (int j = 0; j < n; j++) st1.pop();
				bool f;
				for (; k > i; k--) {
					st2.push(T[k]);
					if (T[k] == A[0]) {
						f = true;
						int end1 = st2.size - n;
						if (end1 < 0) continue;
						int idx1 = 0;
						for (int j = st2.size -1; j >= end1; j--, idx1++)
							if (st2.st[j] != A[idx1]) {
								f = false;
								break;
							}
						if (f) {
							for (int j = 0; j < n; j++) st2.pop();
							k--;
							break;
						}
					}
				}
			}
		}
	}
	int idx = 0, nn=st1.size;
	for (; idx < nn; idx++) T[idx] = st1.st[idx];
	for (int i = st2.size - 1; i >= 0; i--, idx++) T[idx] = st2.st[i];
	for (int i = 0; i < idx; i++) {
		ans.push(T[i]);
		if (T[i] == A[n - 1]) {
			bool find = true;
			int end = ans.size - n;
			if (end < 0) continue;
			int idx = n - 1;
			for (int j = ans.size - 1; j >= end; j--, idx--)
				if (ans.st[j] != A[idx]) {
					find = false;
					break;
				}
			if (find) {
				for (int j = 0; j < n; j++) ans.pop();
			}
		}
	}
	cout << ans.st << '\n';
	return 0;
}