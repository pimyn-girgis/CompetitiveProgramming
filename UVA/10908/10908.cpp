/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10908 UVA
* Link    : https://onlinejudge.org/external/109/p10908.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <unordered_set>
using namespace std;

int m, n, q;
int r, c, ans;

char board[105][105];
unordered_set<char> square;

bool unique_char(int ifrom, int ito, int jfrom, int jto) {
	for (int i = ifrom; i <= ito; ++i) {
		for (int j = jfrom; j <= jto; ++j) {
			if (square.insert(board[i][j]).second) {
				return false;
			}
		}
	}

	return true;
}

bool is_valid(int k) {
	int ifrom = r - k, ito = r + k;
	int jfrom = c - k, jto = c + k;
	return ito < m && ifrom >= 0
	    && jto < n && jfrom >= 0
	    && unique_char(ifrom, ito, jfrom, jto);
}

void solve() {
	square.clear();
	square.insert(board[r][c]);
	ans = 1;

	while (is_valid((ans + 2)/ 2)) {
		ans += 2;
	}
}

int main() {
	int tc; scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d %d\n", &m, &n, &q);

		for (int i = 0; i < m; ++i) {
			fgets(board[i], sizeof(board[i]), stdin);
		}

		printf("%d %d %d\n", m, n, q);
		while (q--) {
			scanf("%d %d\n", &r, &c);
			solve(); printf("%d\n", ans);
		}
	}

	return 0;
}
