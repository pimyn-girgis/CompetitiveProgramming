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
#include <numeric>
using namespace std;

int solve(int n, int k, int b) {
	if (n == 0) {
		return b / k;
	}
	
	b += n;
	int extra = b / k;
	return n + solve(extra, k, b - extra * k);
}

int main() {
	int n, k;

	while (scanf("%d %d", &n, &k) != EOF) {
		printf("%d\n", solve(n, k, 0));
	}

	return 0;
}
