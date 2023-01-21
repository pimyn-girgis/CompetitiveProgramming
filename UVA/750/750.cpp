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
#include <cstdlib>

using namespace std;

int row[8], a, b, sol_num;

bool is_valid(int r, int c) {
	for(int i = 0; i < c; ++i) {
		if (row[i] == r || abs(row[i] - r) == abs(i - c)) {
			return false;
		}
	}

	return true;
}

void backtrack(int c = 0) {
	if (c == 8) {
		printf("%2d      ", sol_num++);
		for (int i = 0; i < 8; ++i) {
			printf("%d%c", row[i] + 1, i == 8 - 1? '\n' : ' ');
		}
		return;
	}

	for (int r = 0; r < 8; ++r) {
		if (c == b && r != a) {
			continue;
		}

		if (is_valid(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
	}
}

int main() {
	int tc;
	scanf("%d\n", &tc);
	
	while (tc--) {
		sol_num = 1;

		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		scanf("%d %d\n", &a, &b); --a; --b;
		backtrack();

		if(tc) printf("\n");
	}

	return 0;
}
