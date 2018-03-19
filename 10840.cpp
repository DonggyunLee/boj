#include <iostream>
#include <vector>
#include <set>
using namespace std;

char A[1501], B[1501];
int nA, nB;

template<typename T>
inline void _swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
inline void _strcpy(char *dest, char *src) {
	int i;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = 0;
}
set<vector<int>> arrA;
int solve() {
	for (int i = nA; i >= 1; i--) {
		vector<int> tmp(26);
		int na = nA - i + 1;
		int aa = 0, bb = 0;
		for (int k = 0; k < i; k++) 
			tmp[A[k] - 'a']++;
		arrA.insert(tmp);
		for (int j = 1; j < na; j++) {
			aa = A[j - 1] - 'a', bb = A[i + j - 1] - 'a';
			tmp[aa]--;
			tmp[bb]++;
			arrA.insert(tmp);
		}
	}
	for (int i = nA; i >= 1; i--) {
		vector<int> tmp(26);
		int nb = nB - i + 1;
		int aa = 0, bb = 0;
		for (int k = 0; k < i; k++)
			tmp[B[k] - 'a']++;
		if (arrA.count(tmp)) return i;
		for (int k = 1; k < nb; k++) {
			aa = B[k - 1] - 'a', bb = B[i + k - 1] - 'a';
			tmp[aa]--;
			tmp[bb]++;
			if (arrA.count(tmp)) return i;
		}
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A;
	cin >> B;
	for (nA = 0; A[nA]; nA++);
	for (nB = 0; B[nB]; nB++);
	if (nA > nB) {
		char tmp[1501] = { 0, };
		_strcpy(tmp, A);
		_strcpy(A, B);
		_strcpy(B, tmp);
		_swap(nA, nB);
	}
	cout << solve() << '\n';

	return 0;
}