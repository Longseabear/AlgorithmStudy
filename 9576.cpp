#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;
vector<vector<int>> node(1001);

int visit_A[1001];
int linked_B[1001];
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
	int testCase, to , from,n,m;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &to, &from);
			for (int j = to; j <= from; j++) node[i].push_back(j); 
		}
		memset(linked_B, 0, sizeof(int) * 1001);
		int count = 0;
		for (int i = 1; i <= m; i++) {
			memset(visit_A, 0, sizeof(int) * 1001);
			if (dfs(i)) count++;
		}
		printf("%d\n", count);
		for (int i = 1; i <= m; i++) {
			node[i].clear();
		}
	}
}