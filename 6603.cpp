#include <stdio.h>

int map[14];
int n;
void loop(int pointer[7], int step) {
	if (step == 7) {
		for (int i = 1; i <= 6; i++) {
			printf("%d ", map[pointer[i]]);
		}
		printf("\n");
		return;
	}
	for (int i = pointer[step-1]+1; i < n; i++) {
		pointer[step] = i;
		loop(pointer, step + 1);
	}
}
int main() {
	while (1) {
		int pointer[7] = { -1 };
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &map[i]);
		}
		
		loop(pointer, 1);
		printf("\n");
	}
}