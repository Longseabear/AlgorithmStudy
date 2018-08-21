#include <stdio.h>
#include <set>
using namespace std;
int union_set[1001];
int find(int x) {
	if (x == union_set[x]) return x;
	else return find(union_set[x]);
}
void update(int x, int y) {
	int x_root = find(x);
	int y_root = find(y);
	
	if(x_root!=y_root)
		union_set[y_root] = x_root;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) union_set[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		update(a, b);
	}
	set<int> s;
	for (int i = 1; i <= n; i++) {
		int k = find(i);
		s.insert(k);
	}
	printf("%d", s.size());
}