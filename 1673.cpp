#include <stdio.h>

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) > 0) {
		int coop = n, stamp = 0;
		int chick = 0;
		while (coop) {
			chick += coop;
			stamp += coop;
			coop = stamp / k;
			stamp %= k;
		}
		printf("%d\n", chick);
	}
}