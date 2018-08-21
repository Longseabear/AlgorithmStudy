#include <stdio.h>
#include <string.h>

char a[101];
char b[101];
char c;
int main() {
	scanf("%s%c", a, &c);
	scanf("%c", &c);
	scanf("%s", b);
	if (c == '*') {
		for (int i = 0; i < strlen(a); i++) printf("%c", a[i]);
		for (int i = 1; i < strlen(b); i++) printf("%c", b[i]);
	}
	else {
		int aLen, bLen;
		aLen = strlen(a);
		bLen = strlen(b);
		int maxLen = aLen > bLen ? aLen : bLen;
		if (aLen == bLen) {
			printf("2");
			for (int i = 1; i < aLen; i++) {
				printf("0");
			}
		}
		else {
			if(aLen>bLen){
				for (int i = 0; i < aLen; i++) {
					if (i == aLen - bLen) printf("1");
					else printf("%c", a[i]);
				}
			}
			else {
				for (int i = 0; i < bLen; i++) {
					if (i == bLen - aLen) printf("1");
					else printf("%c", b[i]);
				}
			}
		}
	}
}