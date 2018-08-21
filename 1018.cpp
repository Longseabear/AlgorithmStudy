#include <stdio.h>
#include <algorithm>

using namespace std;
char map[52][52];
int getAlgo(int y, int x) {
	int start_color = 0;
	int ret[2] = { 0, };
	for (int i = 0; i < 8; i++) {
		start_color = !start_color;
		for (int j = 0; j < 8; j++) {
			int object_color = (j + start_color) % 2;;
			if (object_color==0) {
				ret[map[i+y][j+x] == 'W']++;
			}
			else {
				ret[!(map[i + y][j + x] == 'W')]++;
			}
		}
	}
	return min(ret[0], ret[1]);
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	int min_val = 9876543210;
	for (int i = 1; i <= n - 7; i++) {
		for (int j = 1; j <= m - 7; j++) {
			min_val = min(getAlgo(i, j), min_val);
		}
	}
	printf("%d", min_val);
}