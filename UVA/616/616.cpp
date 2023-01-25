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

#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

bool solve(int n, int val, int count = 0) {
	if (count == n) {
		return (val % n == 0 && val >= 0);
	}

	if (val <= 0 || (val - 1) % n) {
		return false;
	}

	return solve(n, val - (val / n) - 1, count + 1);
}

int main() {

	vector<int> div;
	while (scanf("%d", &n), n >= 0) {

		div.clear();
		int sqr = sqrt(n - 1);
		bool flag = false;

		for (int i = 1; i <= sqr; ++i) {
			if ((n - 1) % i == 0) {
				div.push_back(i);
				if (i * i != n - 1) {
					div.push_back((n - 1) / i);
				}
			}
		}

		sort(div.rbegin(), div.rend());

		int ans = -1;
		for (auto u : div) {
			if (solve(u, n)) {
				ans = u;
				break;
			}
		}

		printf("%d coconuts, ", n);
		if (ans != -1) {
			printf("%d people and 1 monkey\n", ans);
		} else {
			printf("no solution\n");
		}
	}

	return 0;
}
