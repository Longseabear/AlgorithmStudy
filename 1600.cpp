#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct work {
	int y;
	int x;
	int step;
	int restK;
	work(int _y, int _x, int _step, int _restK) :y(_y), x(_x), step(_step), restK(_restK) {

	}
};
int map[202][202];
int dp[202][202][31];

int dx[12] = {0,0,1,-1,-2,-2,-1,-1,1,1,2,2};
int dy[12] = { 1,-1,0,0,1,-1,2,-2,2,-2,1,-1 };
int main() {
	int k; scanf("%d", &k);
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int val;
			scanf("%d", &val);
			map[i][j] = !val;
		}
	}
	queue<work> q;
	q.push(work(1,1,0,k));
	// 원숭이 무브로 가는건 의미가 있음, but 말 무브로 원숭이 무브 갔던 곳 가는 건 무의미
	dp[1][1][k] = 1;
	if (1 == m && 1 == n) {
		printf("0");
		return 0;
	}
	while (!q.empty()) {
		work w = q.front();
		q.pop();
		int loop_num = w.restK > 0 ? 12 : 4;

		for (int i = 0; i < loop_num; i++) {
			int next_x = dx[i] + w.x;
			int next_y = dy[i] + w.y;
			if (next_x <= 0 || next_x > m || next_y <= 0 || next_y > n) continue;
			if (map[next_y][next_x] == 1 && dp[next_y][next_x][w.restK] == 0) {
				if (i >= 4 ) {
					if (dp[next_y][next_x][w.restK-1] == 0) {
						dp[next_y][next_x][w.restK-1] = 1;
						q.push(work(next_y, next_x, w.step + 1, w.restK-1));
						if (next_x == m && next_y == n) {
							printf("%d", w.step + 1);
							return 0;
						}
					}
				}
				else {
					dp[next_y][next_x][w.restK] = 1;
					q.push(work(next_y, next_x, w.step + 1, w.restK));
					if (next_x == m && next_y == n) {
						printf("%d", w.step + 1);
						return 0;
					}
				}
			}
		}
	}
	printf("-1");
}