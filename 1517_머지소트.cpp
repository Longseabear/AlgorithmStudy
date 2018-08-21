#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;
int arr[2][500001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
	}
	int iter = 2;
	int currentPos = 0;
	long long count = 0;
	while (iter < (n << 1)) {
		for (int i = 0; i < (n << 1); i += iter) {
			int leftIndex = i;
			int rightIndex = i + iter / 2;
			int indexCount = i;
			if (rightIndex >= n) {
				for (int i = leftIndex; i < n; i++) {
					arr[!currentPos][indexCount++] = arr[currentPos][i];
				}
				break;
			}
			while (leftIndex < i + iter / 2 && rightIndex < i + iter) {
				if (arr[currentPos][leftIndex] < arr[currentPos][rightIndex]) {
					if (arr[!currentPos][indexCount - 1] != arr[currentPos][leftIndex])
						count += (rightIndex - i - iter / 2);

					arr[!currentPos][indexCount++] = arr[currentPos][leftIndex++];
				}
				else if (arr[currentPos][leftIndex] == arr[currentPos][rightIndex]) {
					if (arr[!currentPos][indexCount - 1] != arr[currentPos][leftIndex])
						count += (rightIndex - i - iter / 2);
					arr[!currentPos][indexCount++] = arr[currentPos][leftIndex++];
					if (rightIndex >= n) break;
					arr[!currentPos][indexCount++] = arr[currentPos][rightIndex++];
				}
				else {
					if (rightIndex >= n) break;
					arr[!currentPos][indexCount++] = arr[currentPos][rightIndex++];
				}
			}
			for (int k = leftIndex; k < i + iter / 2; k++) {
				if(arr[!currentPos][indexCount-1]!=arr[currentPos][k])
					count += (rightIndex - i - iter / 2);
				arr[!currentPos][indexCount++] = arr[currentPos][k];
			}
			for (int k = rightIndex; k < i + iter && k<n; k++) {
				arr[!currentPos][indexCount++] = arr[currentPos][k];
			}
		}
		iter *= 2;
		currentPos = !currentPos;
	}
	printf("%lld\n", count);
}