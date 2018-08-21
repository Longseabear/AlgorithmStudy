#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int dp[101];
int map[101][101];
int main() {
	int n;
	scanf("%d", &n);
	int line;
	scanf("%d", &line);
	for (int i = 0; i < line; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

	queue<int> q;
	q.push(1);
	dp[1] = 1;
	int count = 1;
	while (!q.empty()) {
		int index = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!dp[i] && map[i][index] == 1 && i != index) {
				q.push(i);
				count++;
				dp[i] = 1;
			}
		}
	}
	printf("%d\n", count-1);
}