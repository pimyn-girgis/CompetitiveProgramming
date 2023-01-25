/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11742 UVA
* Link    : https://onlinejudge.org/external/117/p11742.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <map>
#include <cstdio>
#include <numeric>
#include <vector>
using namespace std;

int m, n;
int seating[8];
vector<tuple<int, int, int>> res;

bool is_satisfied(int a, int b, int c) {
	int dist = abs(find(seating, seating + n, a) - find(seating, seating + n, b));
	return c > 0? dist <= c : dist >= -c;
}

bool solve() {
	for (auto &u : res) {
		if (!is_satisfied(get<0>(u), get<1>(u), get<2>(u))) {
			return false;
		}
	}

	return true;
}

int main() {

	while (scanf("%d %d", &n, &m), n || m) {

		iota(seating, seating + n, 0);
		res.clear();

		int a, b, c;
		while (m--) {
			scanf("%d %d %d", &a, &b, &c);
			res.emplace_back(a, b, c);
		}

		int ans = 0;
		do {
			if (solve()) {
				++ans;
			}
		}while (next_permutation(seating, seating + n));

		printf("%d\n", ans);
	}

	return 0;
}
