#include <stdio.h>
#include <string.h>
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		char c[81];
		scanf("%s", c);
		int num = strlen(c);
		int sum = 0;
		int temp_sum = 0;
		for (int i = 0; i < num; i++) {
			if (c[i] == 'O') {
				sum += ++temp_sum;
			}
			else {
				temp_sum = 0;
			}
		}
		printf("%d\n", sum);
	}
}