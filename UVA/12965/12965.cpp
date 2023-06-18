/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12965 UVA
* Link    : https://onlinejudge.org/external/129/p12965.pdf
**************************************************************
* Observation: The answer is either zero or one of the "ideal"
* prices for the producers or consumers.
**************************************************************
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int pro[10005], con[10005];
set<int> prices;

int main() {
	prices.clear(); prices.insert(0);
	int tc; scanf("%d", &tc);
	while (tc--) {
		int p, c; scanf("%d%d", &p, &c);

		for (int i = 0; i < p; ++i) {
			scanf("%d", pro + i);
			prices.insert(pro[i]);
		}
		for (int i = 0; i < c; ++i) {
			scanf("%d", con + i);
			prices.insert(con[i]);
		}

		sort(pro, pro + p);
		sort(con, con + c);

		int angry = 1e9, ans = 0;

		for (int u : prices) {
			// 1 1 1 2 2 3 3 pro
			// 1 1 2 2 3 3 3 con
			// u = 2
			int cur_angry = p - (upper_bound(pro, pro + p, u) - pro)
							      + lower_bound(con, con + c, u) - con;

			if (cur_angry < angry) {
				ans = u;
				angry = cur_angry;
			}
		}

		printf("%d %d\n", ans, angry);
	}
	return 0;
}
