#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct Node {
	int val;
	bool res;
}node;
int N[101];
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int n, obj;
		queue<node> q;

		scanf("%d %d", &n, &obj);
		for (int i = 0; i < n; i++) {
			scanf("%d", &N[i]);
			Node n;
			N[i] *= -1;
			n.val = N[i];
			if (i == obj) {
				n.res = true;
			}
			else {
				n.res = false;
			}
			q.push(n);
		}

		sort(N, N + n);
		int res = 0;
		int current_max = 0;
		while (!q.empty()) {
			Node n = q.front();
			q.pop();
			if (n.val == N[current_max]) {
				current_max++;
				if (n.res) break;
				else res++;
			}
			else q.push(n);
		}
		printf("%d\n", res+1);
	}
}