/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 1047 UVA
* Link    : https://onlinejudge.org/external/10/p1047.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, t, m;
int tow[21];
struct com {
	bool inc[21];
	int amount;
};

com arr[21];
int ans;
vector<int> comb;
vector<int> temp;

int get_sum() {
	
	int sum = tow[temp[0]]; //If we have only one tower, there are no common zones

	for (int i = 1; i < t; ++i) { //for each tower i we add
		sum += tow[temp[i]];
		for (int j = 0; j < m; ++j) { //we check all the common areas
			if (arr[j].inc[temp[i]]) { //if one common area contains i
				for (int k = 0; k < i; ++k) { //check to see if another tower we already have is in the same area
					if (arr[j].inc[temp[k]]) { //if so, then remove the amount of common people and break
						sum -= arr[j].amount;
						break; //if you do not break, you may remove the same set of people more than once
					}
				}
			}
		}
	}

	return sum;
}

void solve(int i, int t) {

	if (!t) {
		int val = get_sum();
		if (val > ans) {
			ans = val;
			comb = temp;
		}
		return;
	}

	for (; i <= n - t; ++i) {
		temp.push_back(i);
		solve(i + 1, t - 1);
		temp.pop_back();
	}
}

int main() {

	int tc = 0;
	while (scanf("%d %d", &n, &t), n || t) {

		comb.clear();
		memset(arr, 0, sizeof(arr));
		ans = 0;

		for (int i = 0; i < n; ++i) {
			scanf("%d", tow + i);
		}

		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int cnt; scanf("%d", &cnt);

			while (cnt--) {
				int num; scanf("%d", &num);
				arr[i].inc[num - 1] = true;
			}

			scanf("%d", &arr[i].amount);;
		}

		solve(0, t);

		printf("Case Number  %d\n", ++tc);
		printf("Number of Customers: %d\n", ans);
		printf("Locations recommended:");
		for (auto u : comb) { printf(" %d", u + 1); }
		printf("\n\n");

	}

	return 0;
}
