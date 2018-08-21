#include <stdio.h>
#include <string.h>
char s[1001];
int len;
int checkPelin(int num) {
	for (int i = 0; i < num / 2; i++) {
		if (num-i-1 >= len) continue;
		if ( s[i] != s[num - i - 1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i <= len; i++) {
		if (checkPelin(i + len)) {
			printf("%d\n", i + len);
			return 0;
		}
	}
}