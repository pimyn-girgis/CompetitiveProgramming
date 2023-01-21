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
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int sol[5], temp[5], best;
int city[5][5];

int min_dist(int i, int j) {
	int ret = 1e9;

	for (int k = 0; k < 5; ++k) {
		ret = min(ret, abs(temp[k] / 5 - i) + abs(temp[k] % 5 - j));
	}
	
	return ret;
}

int calc() {
	int sum = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (city[i][j]) {
				sum += city[i][j] * min_dist(i, j);
			}
		}
	}

	return sum;
}

void solve(int pos = 0, int st = 0) {
	if (pos == 5) {
		int temp_val = calc();

		if (temp_val < best) {
			best = temp_val;
			memcpy(sol, temp, sizeof(sol));
		}

		return;
	}

	for (int val = st; val < 25; ++val) {
		temp[pos] = val;
		solve(pos + 1, val + 1);
	}
}

int main() {
	int tc; scanf("%d", &tc);

	while (tc--) {
		best = 1e9;
		memset(city, 0, sizeof(city));

		int n; scanf("%d", &n);
		while (n--) {
			int row, col, val; scanf("%d %d %d", &row, &col, &val);
			city[row][col] = val;
		}

		solve();
		for (int i = 0; i < 5; ++i) {
			printf("%d%c", sol[i], i == 5 - 1? '\n' : ' ');
		}
	}

	return 0;
}
