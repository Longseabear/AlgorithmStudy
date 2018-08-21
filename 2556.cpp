#include <stdio.h>
#include <memory.h>
#define INFINITY 100000000
#define MIN(a,b) ((a)>(b)?(b):(a))
int dp[65536][16], cost[16][16]; // i->j
int n;
int checkSuccess(int valied)
{
	if (valied == ((1 << n) - 1))
		return 1;
	return 0;
}
int travel(int valied, int cul)
{
	int &res = dp[valied][cul];
	if (res != -1)
		return res;

	if (checkSuccess(valied))
	{
		return cost[cul][0] == 0 ? INFINITY : res=cost[cul][0];
	}
	else {
		res = INFINITY;
		for (int i = 0; i < n; i++)
		{
			if (valied & (1 << i) || cost[cul][i] == 0)
				continue;
			res = MIN(res, travel(valied + (1 << i), i) + cost[cul][i]);
		}
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d", travel(1, 0));
	return 0;
}