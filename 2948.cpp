#include <stdio.h>
char month_[7][10] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday"};

int main() {
	int max_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int max_day_sum[13] = {};
	int month, day;
	scanf("%d %d", &day, &month);

	// 4ø˘ 1¿œ -> 91¿œ
	for (int i = 2; i < 13; i++) {
		max_day_sum[i] = max_day[i - 1] + max_day_sum[i - 1];
	}
	int a = max_day_sum[month] + day;
	printf("%s\n", month_[a % 7]);
}