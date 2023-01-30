/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11351 UVA
* Link    : https://onlinejudge.org/external/113/p11351.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
using namespace std;

int solve(int n, int k) {
	return n == 1? 0 : (k + solve(n - 1, k)) % n;
}

int main() {
	int tc; scanf("%d", &tc);

	for (int no = 1; no <= tc; ++no) {
		int n, k; scanf("%d %d", &n, &k);
		printf("Case %d: %d\n", no, solve(n, k) + 1);
	}

	return 0;
}
