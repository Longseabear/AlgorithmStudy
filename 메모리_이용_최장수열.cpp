#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[1000001];
int main() {
	int n; vector<int> v;
	scanf("%d", &n);
	int max_len = 0;
	while (n--)
	{
		int tmp;
		scanf("%d", &tmp);
		max_len = max(max_len, tmp);
		if (map[tmp - 1] != 0) {
			map[tmp] = map[tmp - 1] + 1;
			map[tmp - 1] = 0;
		}
		else if (map[tmp] == 0) map[tmp] = 1;
	}
	int max_val = 0;
	for (int i = 1; i <= max_len; i++) {
		max_val = max(max_val, map[i]);
	}
	printf("%d", max_val);
	return 0;
}