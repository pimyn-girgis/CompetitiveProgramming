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
#include <vector>
#include <cmath>
using namespace std;

int n;
int arr[1005];

int main() {

	vector<int> sums;
	sums.reserve(1e6 + 5);
	int case_no = 1;

	while (scanf("%d", &n), n) {

		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}

		sums.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				sums.push_back(arr[i] + arr[j]);
			}
		}

		printf("Case %d:\n", case_no++);

		int ans = sums[0];
		int m; scanf("%d", &m);
		while (m--) {
			int val; scanf("%d", &val);
			for (auto u : sums) {
				if (abs(u - val) < abs(ans - val)) {
					ans = u;
				}
			}
			printf("Closest sum to %d is %d.\n", val, ans);
		}
	}

	return 0;
}
