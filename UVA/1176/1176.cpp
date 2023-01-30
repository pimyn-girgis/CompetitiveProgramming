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
#include <vector>
using namespace std;

int solve(int n) {
	int shift = 32 - __builtin_clz(n) - 1;
	int survivor = ((n & ~(1 << shift)) << 1) | 1;
	return n == survivor? 2 * n : (n - survivor) + solve(survivor);
}

int main() {
	int n;

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", solve(n));
	}

	return 0;
}
