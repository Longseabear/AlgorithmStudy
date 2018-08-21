#include <stdio.h>
#include <time.h>
int time2int(int h, int m) {
	return h * 60 + m;
}
void int2Time(int t) {
	t = t % time2int(24, 0);
	printf("%d %d\n", t/60, t%60);
}
int main() {
	int hour, minute;
	int add_time;
	scanf("%d %d %d", &hour, &minute, &add_time);
	int2Time(time2int(hour, minute)+add_time);
}