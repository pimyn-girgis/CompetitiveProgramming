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
#include <unordered_set>
#include <cmath>
using namespace std;

int main() {

	int n;
	printf("PERFECTION OUTPUT\n");

	while (scanf("%d", &n), n) {
		int sqr = sqrt(n);
		int sum = -n;

		for (int i = 1; i <= sqr; ++i) {
			if (n % i == 0) {
				sum += i;
				if (i != n / i) {
					sum += n / i;
				}
			}
		}

		printf("%5d  ", n);
		if (sum == n) {
			printf("PERFECT\n");
		} else if (sum < n) {
			printf("DEFICIENT\n");
		} else {
			printf("ABUNDANT\n");
		}
	}

	printf("END OF OUTPUT\n");

	return 0;
}
