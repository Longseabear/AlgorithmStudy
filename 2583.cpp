#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[102][102];
vector<int> rv;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void setMap(int sx, int sy, int ex, int ey) {
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			map[i][j] = 0;
		}
	}
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			map[i][j] = 1;

	while (k--) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		setMap(sx + 1, sy + 1, ex, ey);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				int res = 1;
				map[i][j] = 0;
				queue<pair<int,int>> q;
				q.push(pair<int, int>(i, j));
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						if (map[cur.first + dy[k]][cur.second + dx[k]] == 1) {
							res++;
							map[cur.first + dy[k]][cur.second + dx[k]] = 0;
							q.push(pair<int, int>(cur.first + dy[k], cur.second + dx[k]));
						}
					}
				}
				rv.push_back(res);
			}
		}
	}
	
	printf("%d\n", rv.size());
	sort(rv.begin(), rv.end());
	for (int k : rv) {
		printf("%d ", k);
	}
}