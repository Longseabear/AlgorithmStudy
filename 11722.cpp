#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int arr[1001];
int main()
{
	int n; vector<int> v;
	scanf("%d", &n);
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n / 2; i++) {
		int temp = 0;
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
	int count = 0;
	while (n--)
	{
		int tmp = arr[count++];
		if (tmp > v.back())
			v.push_back(tmp);
		else
			*lower_bound(v.begin(), v.end(), tmp) = tmp;
	}
	printf("%d", v.size() - 1);
	return 0;
}