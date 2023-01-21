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
#include <set>
#include <unordered_set>
using namespace std;

set<int> points;

void preprocess() {
	points.insert(50);
	for (int i = 0; i <= 20; ++i) {
		points.insert({i, 2 * i, 3 * i});
	}
}

int main() {
	preprocess();

	int n;
	while (scanf("%d", &n), n > 0) {
		int count = 0;
		set< set<int> > comb;

		for (auto u : points) {
			for (auto v : points) {
				for (auto w : points) {
					if (u + v + w == n) {
						++count;
						comb.insert({u, v, w});
					}
				}
			}
		}

		if (count) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, (int)comb.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, count);
		} else {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		printf("**********************************************************************\n");
	}

	printf("END OF OUTPUT\n");

	return 0;
}
