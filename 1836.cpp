#include <stdio.h>
#include <math.h>
int main() {
	long long x, y;
	while (scanf("%lld %lld", &x, &y) == 2) {

		long long z = (long long)y * 100 / x;
		long long left = 1;
		long long right = 10000000000000ll;
		while (left < right) {
			long long mid = (left + right) / 2;
			if (z != (y + mid) * 100 / (x + mid))right = mid;
			else left = mid + 1;
		}
		if (z >= 99)printf("-1\n");
		else printf("%d\n",left);
	}
}