#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>

int map[102][102];
int dp[102][102][4];

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
using namespace std;

int mapping_direction(int val) {
	switch (val)
	{
	case 1:
		return RIGHT;
	case 2:
		return LEFT;
	case 3:
		return DOWN;
	case 4:
		return UP;
	default:
		break;
	}
}
int objY, objX, objDir;
int n, m, sY, sX, sDir;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1, 0, 1 , 0 };

typedef struct WORKER {
	int x, y;
	int dir;
	int step;
	WORKER(int _y, int _x, int _dir, int _step)
	{
		y = _y;
		x = _x;
		dir = _dir;
		step = _step;
	}
}Worker;
int main() {
	memset(dp, -1, sizeof(int) * 102 * 102 * 4);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			map[i][j] = !map[i][j];
		}
	}
	scanf("%d %d %d", &sY, &sX, &sDir);
	scanf("%d %d %d", &objY, &objX, &objDir);
	sDir = mapping_direction(sDir);
	objDir = mapping_direction(objDir);
	queue<Worker> q;
	q.push(Worker(sY, sX, sDir, 0));
	dp[sY][sX][sDir] = 0;

	while (!q.empty()) {
		Worker current = q.front();
		q.pop();
		if (dp[objY][objX][objDir] >= 0) break;

		int dir = current.dir;
		int nextStep = current.step + 1;

		//move
		for (int i = 1; i <= 3; i++) {
			int nextX = current.x + dx[dir] * i;
			int nextY = current.y + dy[dir] * i;
			if (map[nextY][nextX] == 0) break;
			if (dp[nextY][nextX][dir] < 0) {
				dp[nextY][nextX][dir] = nextStep;
				q.push(Worker(nextY, nextX, dir, nextStep));
			}
		}
		// left rotation
		if (dp[current.y][current.x][(dir + 1) % 4] < 0) {
			dp[current.y][current.x][(dir + 1) % 4] = nextStep;
			q.push(Worker(current.y, current.x, (dir + 1) % 4, nextStep));
		}
		if (dp[current.y][current.x][(dir -1+ 4) % 4] < 0) {
			dp[current.y][current.x][(dir -1 +4) % 4] = nextStep;
			q.push(Worker(current.y, current.x, (dir - 1 + 4) % 4, nextStep));
		}
	}
	printf("%d", dp[objY][objX][objDir]);
}