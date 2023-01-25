/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 234 UVA
* Link    : https://onlinejudge.org/external/2/p234.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int p, a;
int tv[9], ans[9], times[9];
pair<int, int> ali[9];

int min_dist(int val) {

	auto closer = [val](const int &x, const int &y) {
		return abs(x - val) < abs(y - val);
	};

	return abs(*min_element(times, times + p + 1, closer) - val);
}

int main() {

	int data_set = 0;
	while (scanf("%d", &p), p) {
		int err[5] = { INT_MAX };

		for (int i = 0; i < p; ++i) {
			scanf("%d", tv + i);
		}

		scanf("%d", &a);
		for (int i = 0; i < a; ++i) {
			scanf("%d %d", &ali[i].first, &ali[i].second);
			--ali[i].first;
		}

		sort(tv, tv + p);
		sort(ali, ali + a);

		int temp_err[5];
		do {
			memset(temp_err, 0, sizeof(temp_err));

			for (int i = 1; i <= p; ++i) {
				times[i] = times[i - 1] + tv[i - 1];
			}

			for (int i = 0; i < a; ++i) {
				temp_err[ali[i].first] += min_dist(ali[i].second);
			}

			if (memcmp(temp_err, err, sizeof(err)) < 0) {
				memcpy(err, temp_err, sizeof(err));
				memcpy(ans, tv, p * sizeof(int));
			}
		} while (next_permutation(tv, tv + p));

		printf("Data set %d\n", ++data_set);
		printf("Order: ");
		for (int i = 0; i < p; ++i) {
			printf("%d%c", ans[i], i == p - 1? '\n' : ' ');
		}

		printf("Error: %d\n", accumulate(err, err + 5, 0, [](int a, int val){return val == INT_MAX? a : a + val;}));
	}

	return 0;
}
