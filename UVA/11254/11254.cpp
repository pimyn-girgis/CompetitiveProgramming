/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
**************************************************************
* Approach: 
**************************************************************
* n * (n + 1) / 2
* n^2/2 + n/2
* n / 2 + sqr / 2
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {

	int n;
	while (scanf("%d", &n), n != -1) {
		int sqr = sqrt(n);
		int sum = (sqr * (sqr + 1)) / 2;

		int j = 1, i;

		for (i = sqr + 1; sum != n; ++i) {
			sum += i;
			while (sum > n) {
				sum -= j++;
			}
		}

		printf("%d = %d + ... + %d\n", n, j, i - 1);
	}

	return 0;
}
