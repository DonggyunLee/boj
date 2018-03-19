#include <iostream>
#include <string>
using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	//freopen("11723.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int src=0, num=0;
	for (int i = 0; i < N; i++) {
		char cmd[10] = { 0, };
		scanf("%s", &cmd);
		if (cmd[0] == 'a' && cmd[1]=='d') {
			scanf("%d", &num);
			int temp = 1 << num;
			src |= temp;
		}
		else if (cmd[0] == 'c') {
			scanf("%d", &num);
			int temp = 1 << num;
			int tmp = src & temp;
			if (tmp > 0) printf("1\n");
			else printf("0\n");
		}
		else if (cmd[0] == 'r') {
			scanf("%d", &num);
			int temp = 1 << num;
			src &= ~temp;
		}
		else if (cmd[0] == 't') {
			scanf("%d", &num);
			int temp = 1 << num;
			src^=temp;
		}
		else if (cmd[0] == 'a' && cmd[1]=='l') {
			src = 1 << 21;
			src--;
		}
		else if (cmd[0] == 'e') {
			src = 0;
		}
	}
	return 0;
}