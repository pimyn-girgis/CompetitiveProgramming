/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 1262 UVA
* Link    : https://onlinejudge.org/external/12/p1262.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;

int k;
char g1[6][7], g2[6][7];
vector<string> pass;
char temp_pass[7];

void process(){
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 6; ++i) {
			bool found = false;
			for (int k = 0; k < 6; ++k) {
				if (g2[k][j] == g1[i][j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				g1[i][j] = '\0';
			}
		}
	}
}

void solve(int j) {
	if (j == 5) {
		pass.emplace_back(temp_pass);
		return;
	}

	for (int i = 0; i < 6; ++i) {
		if (g1[i][j]) {
			temp_pass[j] = g1[i][j];
			solve(j + 1);
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);

	while (tc--) {
		pass.clear();
		scanf("%d\n", &k);

		for (int i = 0; i < 6; ++i) {
			fgets(g1[i], sizeof(g1), stdin);
		}
		for (int i = 0; i < 6; ++i) {
			fgets(g2[i], sizeof(g2), stdin);
		}

		process();
		solve(0);
		sort(pass.begin(), pass.end());
		auto last = unique(pass.begin(), pass.end());

		puts(k > last - pass.begin()? "NO" : pass[k - 1].c_str());
	}

	return 0;
}
