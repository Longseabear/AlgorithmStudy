#include <stdio.h>
#include <list>

#include <math.h>
using namespace std;
long long factorial[21];
int n, caseNum;
list<int> lt;
int getValueRank(int v) {
	list<int>::iterator iter;
	int count = 0;
	int res = 0;
	for (iter = lt.begin(); iter != lt.end(); ++iter) {
		count++;
		if (count == v) {
			res = *iter;
			lt.erase(iter);
			break;
		}
	}
	if (res == 0) {
		return *lt.begin();
	}
	return res;
}
int getRankValue(int v) {
	list<int>::iterator iter;
	int count = 0;
	for (iter = lt.begin(); iter != lt.end(); ++iter) {
		count++;
		if (*iter == v) {
			lt.erase(iter);
			break;
		}
	}
	return count;
}
int main() {
	factorial[1] = 1;
	for (int i = 2; i < 21; i++) {
		factorial[i] = i * factorial[i - 1];
	}
	scanf("%d %d", &n, &caseNum);
	for (int i = 1; i <= n; i++) {
		lt.push_back(i);
	}
	if (caseNum == 1) {
		long long k;
		scanf("%lld", &k);
		long long startIndex = k;
		for (int i = 1; i < n; i++) {
			long long totalNum = factorial[n - i + 1];
			long long dupNum = factorial[n - i];

			int rank = ceil(startIndex / (double)dupNum);
			printf("%d ",getValueRank(rank));
			startIndex = startIndex - ((startIndex-1)/dupNum)*dupNum;
		}
		printf("%d ", getValueRank(1));

	}
	else {
		int arr[21];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		long long startIndex = 1;
		for (int i = 1; i <= n; i++) {
			int getRank = getRankValue(arr[i]);
			long long totalNum = factorial[n - i + 1];
			long long dupNum = factorial[n - i];
			startIndex = startIndex + (dupNum*getRank - dupNum + 1) - 1;
		}
		printf("%lld\n", startIndex);
	}
}