#include <stdio.h>
#include <list>
#include <iostream>
#include <time.h>

using namespace std;

char a[300001];
int main()
{
	clock_t begin, end;
	begin = clock();        // �ð�����

	list<int> lt;
	for (int i = 0; i < 300000; i++) {
		a[i] = 'a';
	}
	
	copy(a, a + 300000, std::back_inserter(lt));
	
	end = clock();          // �ð�����
	cout << "����ð� : " << ((end - begin)) << endl;

	char c = 2;
	printf("[%c]", c);
	return 0;
}