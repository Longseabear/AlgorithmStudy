#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[500001];
int lis[8003];
int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);

	for (int i = 0; i != n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		lis[arr[i] + 4000]++;
	}
	int max = -1;
	for (int i = 0; i < 8003; i++) {
		if (max < lis[i]) {
			max = lis[i];
		}
	}
	int nextMax=-1;
	int flag =0;
	int nextIndex;
	for (int i = 0; i < 8003; i++) {
		if (lis[i]==max) {
			if (flag == 1) {
				nextMax = lis[i];
				nextIndex = i;
				break;
			}
			nextMax = lis[i];
			nextIndex = i;
			flag = 1;
		}
	}
	sort(arr, arr + n);
	printf("%d\n", (int)((abs(sum)/ (double)n)+0.5)*(sum<0?-1:1));
	printf("%d\n", arr[n / 2]);
	printf("%d\n", nextIndex - 4000);
	printf("%d\n", arr[n - 1] - arr[0]);

}