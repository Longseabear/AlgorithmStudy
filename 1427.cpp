#include <stdio.h>
#include <string.h>
int num[10];
int main() {
	int n;
	char c[12] = {};
	scanf("%d", &n);
	sprintf(c, "%d", n);
	int k = strlen(c);
	for (int i = 0; i < k; i++) {
		num[c[i]-'0']++;
	}
	for (int i = 9; i >= 0; i--) {
		while (num[i]-- > 0) {
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}