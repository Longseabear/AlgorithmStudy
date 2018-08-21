#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
	int n; vector<int> v;
	scanf("%d", &n);
	v.push_back(0);
	while (n--)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp > v.back())
			v.push_back(tmp);
		else
			*lower_bound(v.begin(), v.end(), tmp) = tmp;
	}
	printf("%d", v.size() - 1);
	return 0;
}