/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/101/p10128.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[14][14][14];

void preprocess() {
	dp[1][1][1] = 1;

	for (int n = 2; n <= 13; ++n) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b) {
				dp[n][a][b] = dp[n-1][a][b] * (n - 2) + dp[n-1][a-1][b] + dp[n-1][a][b-1];
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	preprocess();

	int a, b, n;
	while (tc--) {
		scanf("%d %d %d", &n, &a, &b);
		printf("%d\n", dp[n][a][b]);
	}

	return 0;
}
