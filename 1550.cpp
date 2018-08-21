#include <stdio.h>
#include <string.h>
int main() {
	long long pow16[6] = { 1,16,256,4096,65536,1048576 };
	char c[9];
	long long res = 0;
	scanf("%s", c);
	int cNum = strlen(c);
	int e = 0;
	for (int i = cNum-1; i >= 0; i--) {
		if (c[i] >= '0' && c[i] <= '9') {
			res += ((c[i] - '0') * pow16[e]);
		}
		else {
			res += ((c[i] - 'A' + 10) * pow16[e]);
		}
		e++;
	}
	printf("%lld", res);
}