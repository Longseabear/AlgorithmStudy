#include <stdio.h>
#include <vector>
#include <memory.h>
#include <string.h>

/*
	다시 풀어볼 문제 DFS와 DP를 조합해서 품.
	단 DP를 접근할 때 이런식으로, 한 바퀴 다 구하고 dp[y][x][step] = res_count로 리턴하였다.

*/
using namespace std;
int res;
char map[103][103];
int n, m, k;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char term[81];
int term_len;
int dp[101][101][81];
int backTracking(int, int, int);
int candidate(int, int, int);
int candidate(int y, int x, int current_step) {
	int res_count = 0;
	for (int dir = 0; dir < 4; dir++) {
		for (int kan = 1; kan <= k; kan++) {
			int nx = x + dx[dir] * kan;
			int ny = y + dy[dir] * kan;
			if (map[ny][nx] != 0) {
				if (map[ny][nx] == term[current_step]) {
					res_count += backTracking(ny, nx, current_step);
				}
			}
			else {
				break;
			}
		}
	}
	return dp[y][x][current_step] = res_count;
}
int isSuccess(int y, int x, int step) {
	if (term_len <= step) {
		return dp[y][x][step] = 1;
	}
	if (dp[y][x][step] >= 0) {
		return dp[y][x][step];
	}
	return 0;
}
int backTracking(int y, int x, int step) {
	step++;
	if (isSuccess(y, x, step)) {
		return dp[y][x][step];
	}
	return candidate(y, x, step);
}
int main() {
	char c;
	scanf("%d %d %d%c", &n, &m, &k, &c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("%c", &c);
	}
	scanf("%s", term);
	term_len = strlen(term);
	memset(dp, -1, sizeof(int) * 101 * 101 * 81);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == term[0]) {
				res += backTracking(i, j, 0);
			}
		}
	}
	printf("%d\n", res);
}