#include <stdio.h>

int map[501][501];
int main() {
	int w, h;
	int lastH = -1;
	int res = 0;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) {
		int block;
		scanf("%d", &block);
		if (lastH < block) {
			lastH = block;
		}
		for (int j = 0; j < block; j++) {
			map[j][i] = 1;
		}
	}
	for (int i = 0; i < lastH; i++) {
		int open = 0;
		int exp = 0;
		for (int j = 0; j < w; j++) {
			if (open) {
				if (map[i][j] == 1) {
					res += exp;
					exp = 0;
				}
				else {
					exp++;
				}
			}
			else {
				if (map[i][j] == 1) {
					open = 1;
				}
			}
		}
	}
	printf("%d\n", res);
}