#include <stdio.h>
#include <algorithm>
#include <iostream>

#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int N, B, W;

char s[300001];
int main() {
	scanf("%d %d %d", &N, &B, &W);
	scanf("%s", s);

	int res = 0;
	int left = 0, right = -1;
	int currentW = 0;
	int currentB = 0;
	int currentStep = 0;
	while (++right < N) {
		if (s[right] == 'W') {
			currentW++;
		}
		else {
			currentB++;
		}
		if (currentB > B) {
			while (left <= right && currentB > B) {
				if (s[left] == 'W') {
					currentW--;
				}
				else {
					currentB--;
				}
				left++;
			}
		}
		else if (right - left + 1 > res && currentW >= W) {
			res = right - left + 1;
		}
	}
	printf("%d", res);
}