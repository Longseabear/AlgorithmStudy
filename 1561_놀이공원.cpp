#include <stdio.h>
#include <vector>
#include <algorithm>

typedef struct Node {
	long long val;
	long long idx;
}node;
struct less_than_key
{
	inline bool operator() (const node& struct1, const node& struct2)
	{
		return (struct1.val < struct2.val);
	}
};
struct idx_sort
{
	inline bool operator() (const node& struct1, const node& struct2)
	{
		return (struct1.idx < struct2.idx);
	}
};
using namespace std;
node map[10001];
using namespace std;
long long gcd(long long a, long long b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}
int n, m;
long long getN(long long b) {
	long long sum = 0;
	for (int i = 1; i <= m; i++)
		sum += b / map[i].val;
	return sum;
}
int get_lower_boundery_index(long long start, long long size, long long object) {
	long long low = start, high = size+1;
	while (low < high) {
		long long mid = (low + high) / 2;
		long long val = getN(mid);
		if (val < object) low = mid + 1;
		else high = mid;
	}
	return high;
}
int main()
{
	long long lcmValue;
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &map[i].val);
		map[i].idx = i;
		if (i == 1)
			lcmValue = map[i].val;
		else
			lcmValue = lcm(lcmValue, map[i].val);
	}
	if (n <= m) {
		printf("%d\n", n);
		return 0;
	}
	n -= m;
	sort(map + 1, map + m + 1, less_than_key());
	long long sum = 0;
	sum = getN(lcmValue);
	n = n % sum;
	if (n == 0) {
		printf("%d", m);
		return 0;
	}
	int idx = get_lower_boundery_index(1, lcmValue, n);
	long long want = getN(idx) - n;
	int resIdx = 987654321;
	sort(map + 1, map + m + 1, idx_sort());
	while (want >= 0) {
		if (idx % map[m].val == 0) {
			resIdx = m;
			want--;
		}
		m--;
	}
	printf("%d\n", map[resIdx].idx);
}