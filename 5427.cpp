#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
struct Node {
	int y, x, step;
	Node(int _y, int _x, int _step) : y(_y), x(_x), step(_step) { };
};
using namespace std;

char map[1002][1002];
int dp[1002][1002];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, sx, sy;
char c;
int checkSuccess(int y, int x) {
	if (y == 1 || x == 1 || y == n || x == m) return 1;
	return 0;
}
vector<pair<int, int>> fire;
int getAlgo() {
	queue<Node> q;
	q.push(Node(sy, sx, 0));
	dp[sy][sx] = 1;
	if (checkSuccess(sy, sx)) return 1;
	int res = 0;
	while (!q.empty()) {
		// fire update;
		int fn = fire.size();
		for (int i = 0; i < fn; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = fire[i].second + dx[j];
				int ny = fire[i].first + dy[j];

				if (map[ny][nx] == '.') {
					map[ny][nx] = '*';
					fire.push_back(pair<int,int>(ny,nx));
				}
			}
		}
	
		int s = q.size();
		for (int i = 0; i < s; i++) {
			Node cur = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if (map[ny][nx] == '.' && dp[ny][nx] == 0) {
					if (checkSuccess(ny,nx)) return cur.step + 2;
					dp[ny][nx] = 1;
					q.push(Node(ny, nx, cur.step + 1));
				}
			}
		}
	}
	return -1;
}
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d %d%c", &m, &n, &c);
		memset(map, 0, sizeof(char) * 1002 * 1002);
		memset(dp, 0, sizeof(int) * 1002 * 1002);
		fire = vector<pair<int, int>>();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@') {
					sx = j;
					sy = i;
				}
				else if (map[i][j] == '*') fire.push_back(pair<int, int>(i, j));
			}
			scanf("%c", &c);
		}
		int res = getAlgo();
		if (res == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", res);
	}
}