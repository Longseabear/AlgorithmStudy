#include <cstdio>

int a[22];

int main()
{
	long long m;
	int i, j, n;
	scanf("%d%d", &n, &i);
	if (i == 1)
	{
		scanf("%lld", &m);
		m--;
		for (i = n - 1; i >= 0; i--)
		{
			a[i] = m % (n - i) + 1;
			m /= n - i;
			for (j = i + 1; j < n; j++) if (a[j] >= a[i]) a[j]++;
		}
		for (i = 0; i < n; i++) printf("%d ", a[i]);
	}
	else
	{
		for (i = 0; i < n; i++) scanf("%d", a + i);
		m = 0;
		for (i = 0; i < n; i++)
		{
			m *= n - i;
			for (j = i + 1; j < n; j++) if (a[j] < a[i]) m++;
		}
		printf("%lld\n", m + 1);
	}
}