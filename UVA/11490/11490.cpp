/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11490 UVA
* Link    : https://onlinejudge.org/external/114/p11490.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long unsigned llu ;
const llu mod = 100000007;

int main() {

	llu n;
	while (scanf("%llu", &n), n) {
		bool no_ans = true;

		for (llu b = 1; n > 6 * b * b; ++b) {
			llu a = (n - 6 * b * b) / (7 * b);
			llu len = 2 * a + 3 * b;
			llu wid = 2 * b + a;
			if (n + 2 * a * a == len * wid) {
				printf("Possible Missing Soldiers = %llu\n", (2 * a % mod * a % mod) % mod);
				no_ans = false;
			}
		}


		if (no_ans) {
			printf("No Solution Possible\n");
		}

		printf("\n");

	}

	return 0;
}
