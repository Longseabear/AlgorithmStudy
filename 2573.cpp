#include <stdio.h>
#include <math.h> 
#include <queue>
#include <vector>
int map[302][302];
int temp[302][302];
bool visit[302][302];

int icebug;
int melting;

int dx[4] = { 0 ,0, 1,-1 };
int dy[4] = { 1, -1, 0 , 0 };

int n, m;

using namespace std;

int getZeroArea(int y, int x) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (map[y + dy[i]][x + dx[i]] <= 0) {
			count++;
		}
	}
	return count;
}
int MIN(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(pair<int,int>(y, x));
	visit[y][x] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + cur.second;
			int ny = dy[i] + cur.first;

			if (0 < ny && ny <= n && 0 < nx && nx <= m) {
				if (!visit[ny][nx] && temp[ny][nx] > 0) {
					visit[ny][nx] = true;
					q.push(pair<int, int>(ny, nx));
				}
			}
		}
	}
}
void dfs(int y, int x) {
	visit[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (0 < ny && ny <= n && 0 < nx && nx <= m) {
			if (!visit[ny][nx] && temp[ny][nx] > 0) {
				dfs(ny, nx);
			}
		}
	}
}
int component_icebug() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == false && temp[i][j] > 0) {
				count++;
				bfs(i, j);
			}
		}
	}
	return count;
}
int ceiling(double a) {
	int b = (int)a;
	if ((double)b < (double)a) {
		return b + 1;
	}
	return b;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > 0) {
				icebug++;
			}
		}
	}
	int year = 0;
	while (icebug > melting) {
		int min = 987654321;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] > 0) {
					int zeroArea = getZeroArea(i,j);
					if (zeroArea > 0) {
						min = MIN(min, ceiling(map[i][j]/(double)zeroArea));
					}
				}
			}
		}
		//UPDATE
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] > 0) {
					int zeroArea = getZeroArea(i, j);
					if (zeroArea > 0) {
						temp[i][j] = map[i][j] - zeroArea * min;
						if (temp[i][j] <= 0) {
							melting++;
						}
					}
					else {
						temp[i][j] = map[i][j];
					}
				}
			}
		}
		year += min;
		//Search icebug
		if (component_icebug() > 1) {
			printf("%d\n", year);
			return 0;
		}
		// reinitialization
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = temp[i][j];
				visit[i][j] = false;
			}
		}
	}
	printf("0\n", year);
	return 0;
}