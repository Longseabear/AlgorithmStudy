#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int flag = 0;
	for (int i = 0; i < 31; i++) {
		if (n & (1 << i)) {
			if (flag == 0) {
				flag = 1;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
	}
	printf("1\n");
}