/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 639 UVA
* Link    : https://onlinejudge.org/external/6/p639.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <vector>
using namespace std;

int n;
char board[4][5];

bool in_bounds(int i) {
	return i < n && i >= 0;
}

bool in_bounds(int i, int j) {
	return in_bounds(i) && in_bounds(j);
}

//Can I input a rook here?
bool is_valid(int i, int j) {

	if (board[i][j] == 'X') {
		return false;
	}

	const int dx[4] = {-1, 1, 0, 0};
	const int dy[4] = {0, 0, -1, 1};

	for (int k = 0; k < 4; ++k) {
		for (int x = i + dx[k], y = j + dy[k]; in_bounds(x, y); x += dx[k], y += dy[k]) {
			if (board[x][y] == 'X') {
				break;
			} else if (board[x][y] == 'r') {
				return false;
			}
		}
	}

	return true;
}


int solve(int i = 0, int j = 0, int cur = 0) {
	if (j == n) {
		++i;
		j = 0;
	}

	if (i == n) {
		return cur;
	}

	int rook = -1;
	int non_rook = solve(i, j + 1, cur);

	if (is_valid(i, j)) {
		board[i][j] = 'r';
		rook = solve(i, j + 1, cur + 1);
		board[i][j] = '.';
	}

	return max(rook, non_rook);
}

int main() {
	while (scanf("%d", &n), n) {

		for (int i = 0; i < n; ++i) {
			scanf("%s", board[i]); 
		}

		printf("%d\n", solve());

	}
	return 0;
}
