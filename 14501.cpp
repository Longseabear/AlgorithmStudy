#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int dp[302][302];

int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1, 2,-2,2,-2,1,-1 };
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(int) * 302 * 302);

		int startX, startY, endX, endY;
		scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
		queue<pair<int, int>> q;
		q.push(pair<int, int>(startY, startX));
		dp[startY][startX] = 1;
		int step = 0;
		while (!q.empty()) {
			int cur_q_size = q.size();
			for (int idx = 0; idx < cur_q_size; idx++) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int i = 0; i < 8; i++) {
					int ny = cur.first + dy[i];
					int nx = cur.second + dx[i];
					if (ny >= n || nx >= n || nx < 0 || ny < 0 || dp[ny][nx]) continue;
					dp[ny][nx] = 1;
					q.push(pair<int, int>(ny, nx));
					if (ny == endY && nx == endX) {
						printf("%d\n", step + 1);
						goto end;
					}
				}
			}
			step++;
		}
		printf("%d\n", 0);
	end:;

	}
}