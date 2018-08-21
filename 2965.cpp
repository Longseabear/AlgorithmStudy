#include <stdio.h>
#include <algorithm>
using namespace std;
int a[3];
int main() {
	int count = 0;
	scanf("%d %d %d", &a[0],&a[1],&a[2]);
	if (a[2] - a[0] > 2) {
		count++;
		if (a[2] - a[1] > a[1] - a[0]) {
			a[0] = a[1] + 1;
			sort(a, a + 3);
			count += (a[2]-a[1]-1);
		}
		else {
			a[2] = a[1] - 1;
			sort(a, a + 3);
			count += (a[1] - a[0] - 1);
		}		
	}

	printf("%d", count);
}