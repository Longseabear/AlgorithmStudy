#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, rec;
	scanf("%d %d", &n, &rec);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	int count = 0;
	vector<int> v;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (rec == ++count) {
			v.push_back(cur);
			count = 0;
		}
		else q.push(cur);
	}
	printf("<");
	for (int i = 0; i < n-1; i++)
		printf("%d, ", v[i]);
	printf("%d>", v[n - 1]);
}