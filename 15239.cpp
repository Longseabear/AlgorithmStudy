#include <stdio.h>
#include <memory.h>
#include <string.h>
char check[100] = "+_)(*&^%$#@!./,;{}";

int val[5];
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int n;
		memset(val, 0, sizeof(int) * 5);
		scanf("%d\n", &n);
		if (n >= 12) val[0] = 1;
		for (int i = 0; i < n; i++) {
			char c;
			scanf("%c", &c);
			if (c >= '0' && c <= '9') val[1] = 1;
			else if (c >= 'a' && c <= 'z') val[2] = 1;
			else if (c >= 'A' && c <= 'Z') val[3] = 1;
			else {
				for (int i = 0; i< strlen(check); i++) {
					if (c == check[i]) {
						val[4] = 1;
						break;
					}
				}
			}
		}
		bool che = true;
		for (int i = 0; i < 5; i++) {
			if (val[i] == 0) {
				che = false;
				break;
			}
		}
		if (che) printf("valid\n");
		else printf("invalid\n");
		char c;
		scanf("%c", &c);
	}
}