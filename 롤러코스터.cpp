#include <stdio.h>

void pirntChar(char c, int i) {
	while (i--) {
		printf("%c", c);
	}
}
int min = 987654321;
int minIdxX, minIdxY;
void getSolution(int n, int m) {
	if (n % 2 == 0 && m % 2 == 0) {
		for (int i = 0; i < n; i+=2) {
			if (minIdxY != i + 1 && minIdxY != i) {
				pirntChar('R', m-1);
				pirntChar('D', 1);
				pirntChar('L', m-1);
				pirntChar('D', 1);
			}
			else {
				int flag = 0;
				for (int j = 0; j < m - 1; j++) {
					if (minIdxX == j) {
						pirntChar('R', 1);
					}
					else {
						if (flag) {
							pirntChar('U', 1);
							pirntChar('R', 1);
						}
						else {
							pirntChar('D', 1);
							pirntChar('R', 1);
						}
						flag = !flag;
					}
				}
				if (i + 2 < n) {
					if (flag == 0) {
						pirntChar('D', 1);
					}
					pirntChar('D', 1);
					pirntChar('L', m-1);
					pirntChar('D', 1);
					getSolution(n - (i + 2)-1, m);
					return;
				}
				else {
					if (flag == 0) {
						pirntChar('D', 1);
					}
				}
			}
		}
	}
	else {
		if (n % 2 == 0) {
			int flag = 0;
			for (int i = 0; i < m - 1; i++) {
				if (flag == 0) {
					pirntChar('D', n-1);
					pirntChar('R', 1);
				}
				else {
					pirntChar('U', n-1);
					pirntChar('R', 1);
				}
				flag = !flag;
			}
			pirntChar('D', n-1);
		}
		else {
			int flag = 0;
			for (int i = 0; i < n - 1; i++) {
				if (flag == 0) {
					pirntChar('R', m-1);
					pirntChar('D', 1);
				}
				else {
					pirntChar('L', m-1);
					pirntChar('D', 1);
				}
				flag = !flag;
			}
			pirntChar('R', m-1);
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int val;
			scanf("%d", &val);
			if (val < min && ((i%2!=j%2))) {
				min = val;
				minIdxX = j;
				minIdxY = i;
			}
		}
	}
	getSolution(n, m);
}