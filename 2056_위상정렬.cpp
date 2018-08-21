#include <stdio.h>
#include <queue>

#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;


struct Node {
	int cost;
	int indegree;
	Node() {
		indegree = 0;
	}
};
char map[10001][10001];
int result[10001];
Node node[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int work_time, pre_num;
		scanf("%d %d", &work_time, &pre_num);
		node[i].cost = work_time;
		for (int j = 1; j <= pre_num; j++) {
			int val;
			scanf("%d", &val);
			map[val][i] = 1;
			node[i].indegree++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (node[i].indegree == 0) { 
			q.push(i);
			result[i] = node[i].cost;
		}
	}

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[currentNode][i]) {
				result[i] = MAX(result[i], result[currentNode] + node[i].cost);
				node[i].indegree--;
				if (node[i].indegree == 0) q.push(i);
			}
		}
	}

	int result_max = 0;
	for (int i = 1; i <= n; i++) {
		result_max = MAX(result_max, result[i]);
	}
	printf("%d", result_max);
}