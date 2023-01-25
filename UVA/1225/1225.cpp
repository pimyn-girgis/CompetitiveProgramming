/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int cnt[10];

int main() {
	int tc; scanf("%d", &tc);

	while (tc--) {
		memset(cnt, 0, sizeof(cnt));
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int val = i;
			while (val) {
				++cnt[val % 10];
				val /= 10;
			}
		}

		for (int i = 0; i < 10; ++i) {
			printf("%d%c", cnt[i], i == 9? '\n' : ' ');
		}
	}

	return 0;
}
