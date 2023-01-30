/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 151 UVA
* Link    : https://onlinejudge.org/external/1/p##########.pdf
**************************************************************
* Approach: Classis Josephus problem
**************************************************************
*/

#include <cstdio>

int solve(int n, int k) {
	return n == 1? 0 : (k + solve(n - 1, k)) % n;
}

int main() {

	int n;
	while (scanf("%d", &n), n) {
		int k = 1;

		while(solve(n - 1, k) != 11) {
			++k;
		}

		printf("%d\n", k);
	}

	return 0;
}
