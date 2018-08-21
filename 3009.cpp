#include <stdio.h>

int main() {
	int c[6];
	for (int i = 0; i < 6; i++) {
		scanf("%d", &c[i]);
	}
	printf("%d %d", c[0] == c[2] ? c[4] : (c[2] == c[4] ? c[0] : c[2]), c[1] == c[3] ? c[5] : (c[3] == c[5] ? c[1] : c[3]));
}