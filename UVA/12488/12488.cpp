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
#include <algorithm>
#include <tuple>
using namespace std;

int start[25];
int finish[25];

int main() {

	int n;
	while (scanf("%d", &n) != EOF) {

		for (int i = 0; i < n; ++i) {
			scanf("%d", start + i);
		}

		for (int i = 0; i < n; ++i) {
			scanf("%d", finish + i);
		}

		int ans = 0;

		for (int i = 0; i < n; ++i) {
			int correct_pos = find(start, start + n, finish[i]) - start;
			while (i != correct_pos) {
				++ans;
				swap(start[correct_pos], start[correct_pos - 1]);
				--correct_pos;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
