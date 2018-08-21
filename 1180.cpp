#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
typedef struct STR{
	char c[51];
	int len;
}str;
using namespace std;
struct str_compare{
	bool operator()(const struct STR& a,const struct STR& b) const {
		if (a.len > b.len) {
			return false;
		}
		else if (a.len < b.len) {
			return true;
		}
		else {
			int res = strcmp(a.c, b.c);
			if (res > 0) {
				return false;
			}
			else if (res<0){
				return true;
			}
			else {
				return false;
			}
		}
	}
}; 
int main() {
	int n;
	set<struct STR, str_compare> set_vector;
	set<struct STR, str_compare>::iterator iter;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		struct STR s;
		scanf("%s", s.c);

		s.len = strlen(s.c);
		set_vector.insert(s);
	}
	for (iter = set_vector.begin(); iter != set_vector.end(); iter++) {
		printf("%s\n", iter->c);
	}

}