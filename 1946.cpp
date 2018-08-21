#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef struct person {
	int index;
	int val;
}Person;
Person p1[100001];
Person p2[100001];
char dp[100001];
struct lessThan {
	inline bool operator()(Person& a, Person& b) const {
		return a.val > b.val;
	}
};
struct moreThan {
	inline bool operator()(Person& a, Person& b) const {
		return a.val < b.val;
	}
};
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		memset(dp, 0, sizeof(char) * 100001);
		int n;
		int startIndex = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			p1[i].index = i;
			p2[i].index = i;
			scanf("%d %d", &p1[i].val, &p2[i].val);
		}
		sort(p1, p1 + n, moreThan());
		sort(p2, p2 + n, lessThan());

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (dp[p1[i].index] > 0) continue;
			dp[p1[i].index] = 1;
			res++;
			while (startIndex < n) {
				if (p2[startIndex].index != p1[i].index) {
					dp[p2[startIndex].index] = 1;
					startIndex++;
				}
				else {
					startIndex++;
					break;
				}

			}
		}
		printf("%d\n", res);

	}
}