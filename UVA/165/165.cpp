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
#include <cstring>
#include <vector>
using namespace std;

vector<int> sol[9][9];
int best[9][9];

vector<int> best_stamps;

int get_best(int h, int k) {
    return 0;
}

void preprocess() {
	for (int h = 1; h < 9; ++h) {
		for (int k = 1; k + h <= 9; ++k) {
            get_best(h, k);
            sol[h][k] = best_stamps;
            best_stamps.clear();
		}
	}
}

int main() {
	preprocess();

	int h, k;
	while (scanf("%d %d", &h, &k), h && k) {
		for (int u : sol[h][k]) {
			printf("%3d ", u);
		}
		printf("-> %3d\n", best[h][k]);
	}
	
    return 0;
}

/*
* h = number of stamps
* k = number of denominations
* n(h, k) = largest attainable value (continuous)
*/
