#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct PERSON {
	long long min;
	long long max;
}Person;

struct sorted_max_based
{
	inline bool operator() (const Person& struct1, const Person& struct2)
	{
		long long a = struct1.max;
		long long b = struct2.max;

		return (a < b);
	}
};
Person p[1003];
int main() {
	int n, t;
	scanf("%d %d", &n, &t);

	long long min_sum = 0;
	long long min_max = -1;

	for (int i = 0; i < n; i++) {
		long long l, r;
		scanf("%lld %lld", &l, &r);
		if (min_max < l) {
			min_max = l;
		}
		min_sum += l;
		p[i].min = l;
		p[i].max = r;
	}
	if (t < min_sum) {
		printf("-1\n");
		return 0;
	}
	if (t == min_sum) {
		printf("%d\n", min_max);
		return 0;
	}
	// equalization
	for (int i = 0; i < n; i++) {
		if (min_max >= p[i].max) {
			t -= p[i].max;
			p[i].max = 0;
			p[i].min = 0;
		}
		else {
			p[i].max = p[i].max - min_max;
			p[i].min = 0;
			t -= min_max;
		}
		if (t <= 0) {
			printf("%d\n", min_max);
			return 0;
		}
	}
	sort(p, p+n, sorted_max_based());
	int index = 0;
	while (p[index].max==0) {
		index++;
	}
	while (index < n) {
		long long current_min_max = p[index].max;
		// check
		long long need_min = ceil((double)t / (n - index));
		if (p[index].max >= need_min) {
			printf("%d\n", min_max + need_min);
			return 0;
		}

		// min ¼öÁ¤
		for (int i = index; i < n; i++) {
			p[i].max -= current_min_max;
			t -= current_min_max;
			if (p[i].max == 0) {
				index++;
			}
		}
		min_max += current_min_max;
	}
	printf("-1\n");
	return 0;
}