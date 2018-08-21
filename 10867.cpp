#include <set>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	set<int> s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		s.insert(val);
	}
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		printf("%d ", *iter);
	}
}