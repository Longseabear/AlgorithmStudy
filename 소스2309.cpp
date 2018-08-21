#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n[9];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) continue;
			int sum = 0;
			vector<int> v;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum += n[k];
					v.push_back(n[k]);
				}
			}
			if (sum == 100) {
				sort(v.begin(), v.end());
				for (int k : v) {
					printf("%d\n", k);
				}
				return 0;
			}
		}
	}
}