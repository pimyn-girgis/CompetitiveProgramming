/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11659 UVA
* Link    : https://onlinejudge.org/external/116/p11659.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sys/resource.h>
#include <vector>
#include <unordered_set>
using namespace std;

#define Set(x, y) (x |= (1 << (y)))
#define unset(x, y) (x &= ~(1 << (y)))

int ans;
int says[21][21];
int f, a;

void solve(int i, int rel, int non_rel) {

	if (rel & non_rel) {
		return;
	}

	if (i == f) {
		ans = max(ans, __builtin_popcount(rel));
		return;
	}

	solve(i + 1, rel, non_rel | (1 << i));

	Set(rel, i);
	for (int j = 0; j < f; ++j) {
		if (says[i][j] < 0) {
			Set(non_rel, j);
		} else if (says[i][j] > 0) {
			Set(rel, j);
		}
	}

	solve(i + 1, rel , non_rel);

	return;
}

int main() {

	while (scanf("%d %d\n", &f, &a), f || a) {
		memset(says, 0, sizeof(says));
		ans = 0;

		int x, y;
		int non_rel = 0;
		while (a--) {
			scanf("%d %d", &x, &y);
			auto &ref = says[x - 1][abs(y) - 1];
			if (ref && ref != y) {
				Set(non_rel, x - 1);
			}
			ref = y;
		}

		solve(0, 0, non_rel);
		printf("%d\n", ans);
	}

	return 0;
}
