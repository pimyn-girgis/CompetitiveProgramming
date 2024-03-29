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
#include <cmath>
using namespace std;

int solve(int &n) {
	int shift = 31 - __builtin_clz(n);
	return ((n & ~(1 << shift)) << 1) | 1;
}

int main() {
	int tc; scanf("%d", &tc);

	for (int no = 1; no <= tc; ++no) {
		int n; scanf("%d", &n);
		int rep = -1;

		for (int survivor = -1; survivor != n; n = solve(n)) {
			survivor = n;
			++rep;
		}

		printf("Case %d: %d %d\n", no, rep, n);
	}

	return 0;
}
