#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

char map[52][52];
int indexing[2][52][52];

int visit_A[1001];
int linked_B[1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> node(1001);
int dfs(int cur_a) {
	if (visit_A[cur_a]) return 0;
	visit_A[cur_a] = 1;
	for (int obj_b : node[cur_a]) {
		if (!linked_B[obj_b] || dfs(linked_B[obj_b])) {
			linked_B[obj_b] = cur_a;
			return 1;
		}
	}
	return 0;
}
int main() {
	int n, m;

	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++)
			scanf("%s", map[i] + 1);

	int v = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			while (map[i][j]=='*' && j <= m) {
				indexing[0][i][j] = v;
				j++;
				if (j > m || map[i][j] != '*') {
					v++;
					break;
				}
			}
		}
	}
	int max_v = v;
	v = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			while (map[j][i] == '*' && j <= n) {
				indexing[1][j][i] = v;
				j++;
				if (j > n || map[j][i] != '*') {
					v++;
					break;
				}
			}
		}
	}
	max_v = max_v > v ? max_v : v;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			if (indexing[0][i][j] > 0) node[indexing[0][i][j]].push_back(indexing[1][i][j]);

	int count = 0;
	for (int i = 1; i <= max_v; i++) {
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++;
	}
	printf("%d", count);
}