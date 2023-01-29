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

int ans[10000];

int main() {

	/*
	 * missing = 2a^2
	 * thickness = b
	 * len = 2a + 3b
	 * wid = 2b + a
	 * len * wid = 2a^2 + 7ab + 6b^2
	 * n + 2a^2 = 2a^2 + 7ab + 6b^2
	 * n = 7ab + 6b^2
	 * 7ab = n - 6b^2
	 * a = (n - 6b^2)/7b
	*/

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
