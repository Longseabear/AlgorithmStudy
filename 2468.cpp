#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
int map[102][102];

int dp[101];
int memo[102][102];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	int n;
	int max_div = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			dp[map[i][j]] = 1;
		}
	}
	int res = 1;
	for (int k = 1; k <= 100; k++) {
		if (!dp[k]) continue;
		memset(memo, 0, sizeof(int) * 102 * 102);
		int div = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > k && memo[i][j]==0) {
					div++;
					memo[i][j] = 1;
					queue<pair<int, int>> q;
					q.push(pair<int, int>(i, j));
					while (!q.empty()) {
						int cur_y = q.front().first;
						int cur_x = q.front().second;
						q.pop();

						for (int m = 0; m < 4; m++) {
							if (map[cur_y + dy[m]][cur_x + dx[m]] > k && memo[cur_y + dy[m]][cur_x + dx[m]] == 0) {
								q.push(pair<int, int>(cur_y + dy[m], cur_x + dx[m]));
								memo[cur_y + dy[m]][cur_x + dx[m]] = 1;
							}
						}
					}					
				}
			}
		}
		res = MAX(res, div);
	}
	printf("%d", res);
}