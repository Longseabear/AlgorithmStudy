#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
long long map[100002];
using namespace std;
long long dnq(int left, int right) {
	if (left == right) return map[left]*1;
	long long ret = 0;
	int mid = (left + right) / 2;
	ret = max(dnq(left, mid), dnq(mid + 1, right));

	long long current_height = *min_element(map + mid, map + mid + 2);
	int left_idx = mid;
	int right_idx = mid + 1;
	while (left_idx >= left && right_idx<=right) {
		ret = max(ret, current_height*(right_idx-left_idx+1));
		
		if (map[right_idx + 1] > map[left_idx - 1]) {
			current_height = min(map[right_idx + 1], current_height);
			right_idx++;
		}
		else {
			current_height = min(map[left_idx -1], current_height);
			left_idx--;
		}
	}
	while (left_idx >= left) {
		ret = max(ret, current_height*(right_idx - left_idx + 1));
		current_height = min(map[left_idx - 1], current_height);
		left_idx--;
	}
	while (right_idx <= right) {
		ret = max(ret, current_height*(right_idx - left_idx + 1));
		current_height = min(map[right_idx + 1], current_height);
		right_idx++;
	}
	return ret;
}
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) return 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &map[i]);
		}
		map[n + 1] = 0;
		printf("%lld\n", dnq(1, n));
	}
}