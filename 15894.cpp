#include <stdio.h>
#include <algorithm>
#include <queue>
#include <concurrent_priority_queue.h>
using namespace std;
int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	priority_queue<long long> q;
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		q.push(-val);
	}
	while (m--) {
		long long k = q.top();
		q.pop();
		long long k2 = q.top();
		q.pop();

		q.push(k + k2);
		q.push(k + k2);
	}
	long long sum = 0;
	while (!q.empty()) {
		sum += -q.top();
		q.pop();
	}
	printf("%lld", sum);
}