/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11236 UVA
* Link    : https://onlinejudge.org/external/112/p11236.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
using namespace std;

int sol[4];
const int ten6 = 1e6;
const int ten8 = 1e6;

void solve(int pos = 0, int st = 1, long long sum = 0, long long product = 1) {
	if (pos == 3) {
		if (product <= ten6) {
			return;
		}
		//(d + sum) * 1e6 = d * product
		//sum * 1e6 = d * (product - 1e6)
		//d = (sum * 1e6) / (product - 1e6)
		sol[3] = (sum * ten6) / (product - ten6);
		sum += sol[3]; product *= sol[3];

		if (sum > 2000 || sol[3] < sol[2]) {
			return;
		}

		if (ten8 * sum == product) {
			for (int i = 0; i < 4; ++i) {
				printf("%.2f%c", sol[i]/100.0, i == 3? '\n' : ' ');
			}
		}

		return;
	}

	for (int i = st; sum + i < 2000 && product < 20 * ten8; ++i) {
		sol[pos] = i;
		solve(pos + 1, i, sum + i, product * i);
	}
}

int main() {
	long long product, sum;
	for (int a = 1; a <= 2000 - 3; ++a) {
		for (int b = a; a + b <= 2000 - 2; ++b) {
			for (int c = b; a + b + c <= 2000 - 1; ++c) {
				int d = (a + b + c) * 1e6 / (a * b * c - 1e6);
				product = a * b * c * d;
				sum = (a + b + c + d) * 1e6;
				if (d >= c && sum <= 2000 * 1e6 + 0.01 && sum == product) {
					printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
				}
			}
		}
	}
	return 0;
}
