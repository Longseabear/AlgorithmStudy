#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int visit_A[101];
int linked_B[101];
vector<vector<int>> node(101);

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
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit_A, 0, sizeof(int) * 101);
		if (dfs(i)) count++;
	}
	printf("%d", count);
}