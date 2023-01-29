/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11130 UVA
* Link    : https://onlinejudge.org/external/111/p11130.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int a, b, v, A, s;

	while (scanf("%d %d %d %d %d", &a, &b, &v, &A, &s), a) {
		float D = s * v / 2.0;
		printf("%.0f %.0f\n",
		D * cos(A / 180.0 * M_PI) / a,
		D * sin(A / 180.0 * M_PI) / b);
	}

	return 0;
}
