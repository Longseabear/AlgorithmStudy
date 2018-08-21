#include <math.h>
long long *tree;
int A[10] = { 1,4,2,3,5,1,2,4,5,3 };

typedef long long ll;
using namespace std;

void update(int changed_index, ll diff, int index, int start, int end)
{
	if (changed_index < start || changed_index > end)
		return;

	node[index] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(changed_index, diff, index * 2 + 1, start, mid);
		update(changed_index, diff, index * 2 + 1, mid + 1, end);
	}
}
long long sum(int index, int start, int end, int left, int right)
{
	if (start > right || end < left) // case 1
		return 0;
	else if (start >= left && end <= right) //case 2
		return tree[index];
	else // other case
	{
		int mid = (start + end) / 2;
		return sum(2 * index + 1, start, mid, left, right) + sum(2 * index + 2, mid + 1, end, left, right);
	}
}
long long init(int index, int start, int end)
{
	if (start == end)
		tree[index] = A[start];
	else
		tree[index] = init(index * 2 + 1, start, (start + end) / 2) + init(index * 2 + 2, (start + end) / 2 + 1, end);

	return tree[index];
}
void main()
{
	int N = 10;
	int h = ceil(log2(N));
	int tree_size = 1 << (h + 1);

	tree = new long long[tree_size];
	init(0, 0, N - 1);

	delete[] tree;
}