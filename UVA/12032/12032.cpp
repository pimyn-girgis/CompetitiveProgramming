/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12032 UVA
* Link    : https://onlinejudge.org/external/120/p12032.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int height[100005];
int n;

bool viable(int k) {
	for (int i = 1; i <= n; ++i) {
		const int diff = height[i] - height[i - 1];
		if (diff == k) {
			--k;
		} else if (diff > k) {
			return false;
		}
	}
	return true;
}

int main() {
	int tc; scanf("%d", &tc);

	for (int caseNo = 1; caseNo <= tc; ++caseNo) {
		scanf("%d", &n);

		int j = 0;
		for (int i = 1; i <= n; ++i) { // loop starts from 1 reserving height[0] = 0
			scanf("%d", height + i);
			j = max(j, height[i] + 1);
		}

		int i = 0; int ans = 1e9;
		while (i < j) {
			int mid = (i + j) / 2;
			if (viable(mid)) {
				j = mid;
				ans = mid;
			} else {
				i = mid + 1;
			}
		}

		printf("Case %d: %d\n", caseNo, ans);
	}
	return 0;
}
