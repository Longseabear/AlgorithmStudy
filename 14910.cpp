#include <stdio.h>

int main() {
	int n;
	int flag = 1;
	int current = -1000001;
	while (scanf("%d", &n) != EOF) {
		if (flag) {
			if (n >= current) {
				current = n;
			}
			else {
				flag = 0;
			}
		}
		else {
			continue;
		}
	}
	if (flag) {
		printf("Good\n");
	}
	else {
		printf("Bad\n");
	}
	
}