#include <stdio.h>

int seg[4 * 1000000 + 5];
void changeSegmentValue(int currentNode, int objectNode, int dVal, int left, int right) {

	if (left > objectNode || right - 1 < objectNode) return;
	seg[currentNode] += dVal;
	if (left < right-1) {
		int mid = (left + right) / 2;
		changeSegmentValue(currentNode * 2 + 1, objectNode, dVal, left, mid);
		changeSegmentValue(currentNode * 2 + 2, objectNode, dVal, mid, right);
	}
}
int sumToVal(int currentNode, int objectNode, int left, int right) {
	// 0 ~ 100만까지 존재, 0~objectNode까지의 합이 목표
	int sum = 0;
	if (right - 1 < 0 || objectNode < left) return 0;
	else if (right - 1 <= objectNode && left >= 0) {
		return seg[currentNode];
	}
	else {
		int mid = (left + right) / 2;
		sum = sumToVal(currentNode * 2 + 1, objectNode, left, mid) + sumToVal(currentNode * 2 + 2, objectNode, mid, right);
		return sum;
	}
}
int getNumber(int rank) {
	int low = 1, high = 1000000;
	while (low < high) {
		int mid = (low + high) / 2;
		int val = sumToVal(0, mid - 1, 0, 1000000);
		if (val < rank) low = mid + 1;
		else high = mid;
	}
	changeSegmentValue(0, low - 1, -1, 0, 1000000);
	return low;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int act;
		scanf("%d", &act);
		if (act == 1) {
			int c;
			scanf("%d", &c);
			printf("%d\n", getNumber(c));
		}
		else {
			int weight, num;
			scanf("%d %d", &weight, &num);
			changeSegmentValue(0, weight - 1, num, 0, 1000000);
		}
	}
}