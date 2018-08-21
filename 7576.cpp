#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

struct Node {
	int y;
	int x;
	int step;
	Node(int _y, int _x, int _step) : y(_y), x(_x), step(_step){
	}
};
#define MAX(a,b) ((a)>(b)?(a):(b))
int map[1002][1002];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1 ,-1, 0, 0 };
int main() {
	int n, m;
	int max_step = 0;
	int total_tomato = 0;
	int current_tomato = 0;
	queue<Node> q;
	scanf("%d %d", &m, &n);

	memset(map, -1, 1002 * 1002 *sizeof(int));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) q.push(Node(i,j,0));
			if (map[i][j] == 1 || map[i][j] == 0) total_tomato++;
		}
	}
	current_tomato = q.size();
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (map[cur.y + dy[i]][cur.x + dx[i]] == 0) {
				q.push(Node(cur.y + dy[i], cur.x + dx[i], cur.step + 1));
				max_step = MAX(cur.step+1, max_step);
				map[cur.y + dy[i]][cur.x + dx[i]] = 1;
				current_tomato++;
			}
		}
	}
	printf("%d", current_tomato==total_tomato? max_step : -1);
}