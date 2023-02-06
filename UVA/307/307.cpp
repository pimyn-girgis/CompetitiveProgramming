/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 307 UVA
* Link    : https://onlinejudge.org/external/3/p307.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

bool taken[1000];
int arr[1000];
int len;
int sum;
int n;

bool solve(int i, int k, int cur) {
	if (cur > len) {
		return false;
	}

	if (cur == len) {
		return solve(0, k - 1, 0);
	}

	if (!k) {
		return true;
	}

	for (; i < n; ++i) {
		if (taken[i]) {
			continue;
		}

		taken[i] = true;
		if (solve(i + 1, k, cur + arr[i])) {
			return true;
		}
		taken[i] = false;

		if (cur == 0) {
			return false;
		}

		while (i + 1 < n && arr[i] == arr[i + 1]) {
			++i;
		}
	}

	return false;
}

inline __attribute__((always_inline)) bool valid() {
	return sum % len? false : solve(0, sum / len, 0);
}

int main() {
	while (scanf("%d", &n), n) {
		memset(taken, 0, n);

		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}

		sum = accumulate(arr, arr + n, 0);
		sort(arr, arr + n);
		reverse(arr, arr + n);

		for (len = *arr; !valid(); ++len);

		printf("%d\n", len);
	}

	return 0;
}
