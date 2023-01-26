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
#include <cstdio>
#include <string>
#include <iostream>
#include <numeric>
using namespace std;

char input[11];
string arr[7];
int n;

int solve() {
	string ret = arr[0];

	for (int i = 1; i < n; ++i) {
		int len = min(arr[i].size(), ret.size());
		int rem = 0;

		for (int j = 1; j <= len; ++j) {
			string temp = ret.substr(ret.size() - j, j);
			if (temp == arr[i].substr(0, j)) {
				rem = temp.size();
			}
		}

		ret.resize(ret.size() - rem);
		ret += arr[i];
	}

	return ret.size();
}

int main() {
	int tc; scanf("%d", &tc);

	for (int no = 1; no <= tc; ++no) {
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) {
			scanf("%s", input);
			arr[i] = input;
		}

		sort(arr, arr + n);

		int ans = 1e9;

		do {
			ans = min(ans, solve());
		} while (next_permutation(arr, arr + n));

		printf("Case %d: %d\n", no, ans);

	}

	return 0;
}
