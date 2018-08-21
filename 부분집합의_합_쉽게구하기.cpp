#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int n, s;

int main() {
	scanf("%d %d", &n, &s);
	int cur = 1;
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	int left = 0, right = n - 1;
	int mid = (left + right) / 2;
	vector<int> left_v(1 << (mid + 1));
	vector<int> right_v(1 << (n - mid - 1));
	for (int i = 0; i< (1 << (mid + 1)); i++)
	{
		for (int j = 0; j<mid + 1; j++)
		{
			if (i&(1 << j))
				left_v[i] += v[j];
		}
	}
	for (int i = 0; i<(1 << (n - mid - 1)); i++)
	{
		for (int j = 0; j<n - mid - 1; j++)
		{
			if (i&(1 << j))
				right_v[i] += v[j + mid + 1];
		}
	}
	long long res = 0;
	sort(right_v.begin(), right_v.end());
	for (long long i : left_v) {
		auto idx = equal_range(right_v.begin(), right_v.end(), s - i);
		res += (idx.second - idx.first);
	}
	printf("%lld", res - (s == 0));

}
