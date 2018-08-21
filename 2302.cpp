#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct node {
	int currentPosition;
	vector<int> v;
}Node;
int map[1001][1001];
char bit[1001][31];

int dp[1001];

int n, m;
int hamming(int s, int d) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (bit[s][i] != bit[d][i])
			count++;
	}
	return count;
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%s", &bit[i]);
		for (int j = 1; j < i; j++) {
			int hv = hamming(i, j);
			map[i][j] = hv;
			map[j][i] = hv;
		}
	}

	int start, end;
	scanf("%d %d", &start, &end);

	queue<Node> q;
	Node first;
	first.currentPosition = start;
	first.v.push_back(start);
	q.push(first);
	dp[start] = 1;
	int flag = 0;
	while (!flag && !q.empty()) {
		Node current = q.front();
		q.pop();

		int currentPos = current.currentPosition;
		for (int i = 1; i <= n; i++) {
			if (map[currentPos][i]==1 && !dp[i]) {
				dp[i] = 1;
				Node a = current;
				a.currentPosition = i;
				a.v.push_back(i);
				q.push(a);
				if (i == end) {
					flag = 1;
					break;
				}
			}
		}
	}

	if (q.size() > 0) {
		vector<int> b = q.back().v;
		for (int idx : b) {
			printf("%d ", idx);
		}
	}
	else {
		printf("-1");
	}
}