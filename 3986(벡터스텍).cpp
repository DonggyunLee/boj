#include <stdio.h>

template<typename T>
struct Stack {
	T *arr;
	int size;
	int vsize;
	Stack() {
		size = 0;
		vsize = 4;
		arr = new T[vsize];
	}
	void push(T data) {
		if (size == vsize) {
			T *tmp = new T[vsize];
			for (register int i = 0; i < vsize; i++) tmp[i] = arr[i];
			delete[] arr;
			arr = new T[vsize << 1];
			for (register int i = 0; i < vsize; i++) arr[i]=tmp[i];
			delete[] tmp;
			vsize <<= 1;
		}
		arr[size++] = data;
	}
	void pop() {
		if (size == 0) return;
		arr[--size] = 0;
	}
	T back() {
		return arr[size - 1];
	}
};
int N;

inline int _strlen(char *a) {
	register int i;
	for (i = 0; a[i] != 0; i++);
	return i;
}
int main() {
	freopen("3986input.txt", "r", stdin);
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		char input[100001] = { 0, };
		Stack<char> st;
		scanf("%s", input);
		int n = _strlen(input);
		st.push(input[0]);
		for (int j = 1; j < n; j++) {
			if (st.back() == input[j]) st.pop();
			else st.push(input[j]);
		}
		if (!st.size) ans++;
	}
	printf("%d\n", ans);
	return 0;
}