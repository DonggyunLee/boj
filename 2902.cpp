#include <stdio.h>

int main() {
	freopen("2902input.txt", "r", stdin);
	char ch;
	while (scanf("%c",&ch)!=EOF) {
		if(ch >='A' && ch <='Z')
			printf("%c", ch);
	}
	return 0;
}