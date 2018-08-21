#include <stdio.h>
#include <vector>
#include <memory.h>
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
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int work_num;
		scanf("%d", &work_num);
		while (work_num--) {
			int val;
			scanf("%d", &val);
			node[i].push_back(val);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++;
	}
	for (int i = 1; i <= n && k>0; i++) {
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++, k--;
	}
	printf("%d\n", count);
}