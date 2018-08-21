#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> v;
	for (int i = 0; i < 7; i++) {
		int val;
		scanf("%d", &val);
		if(val%2==1)
			v.push_back(val);
	}
	if (v.empty()) {
		printf("-1");
		return 0;
	}
	int sum = 0;
	int min = 987654321;
	for (int i : v) {
		sum += i;
		if (i < min) min = i;
	}
	printf("%d\n%d", sum, min);
}