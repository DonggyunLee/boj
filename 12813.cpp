//#include <iostream>
//using namespace std;
//#define ll long long
//
//char A[100001], B[100001];
//
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//int _strlen(char *a) {
//	int i;
//	for(i=0;a[i]!=0;i++){}
//	return i;
//}
//int _atoi(char a) {
//	return a - '0';
//}
//int main() {
//	//freopen("12813.txt", "r", stdin);
//	cin >> A;
//	cin >> B;
//	int N = max(_strlen(A), _strlen(B));
//	for (int i = 0; i < N; i++) {
//		int a = _atoi(A[i]);
//		int b = _atoi(B[i]);
//		int c = a & b;
//		cout << c;
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		int a = _atoi(A[i]);
//		int b = _atoi(B[i]);
//		int c = a | b;
//		cout << c;
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		int a = _atoi(A[i]);
//		int b = _atoi(B[i]);
//		int c = a ^ b;
//		cout << c;
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		int a = _atoi(A[i]);
//		if (a == 0) cout << "1";
//		else cout << "0";
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		int b = _atoi(B[i]);
//		if (b == 0) cout << "1";
//		else cout << "0";
//	}
//	cout << endl;
//
//	return 0;
//}