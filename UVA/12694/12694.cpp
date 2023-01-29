/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12694 UVA
* Link    : https://onlinejudge.org/external/126/p12694.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int tc; scanf("%d", &tc);

	vector<pii> times;

	while (tc--) {
		times.clear();

		int b, e;
		while (scanf("%d %d", &b, &e), b || e) {
			times.emplace_back(b, e);
		}

		sort(times.begin(), times.end(), [](const pii &x, const pii &y) {return x.second == y.second? x.first > y.first : x.second < y.second;});
		int last = 0;
		int ans = 0;

		for (auto &u : times) {
			if (u.first >= last) {
				last = u.second;
				++ans;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
