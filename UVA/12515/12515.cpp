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
#include <cstdlib>
using namespace std;

char movie[1005][105];
int movie_len[1005];
char clip[105];

int ham_dist(char *movie) {
	int ret = 0;

	for (int i = 0; clip[i] ; ++i) {
		if (movie[i] != clip[i]) {
			++ret;
		}
	}

	return ret;
}

int main() {
	int m, q;
	int ans, max_val;

	scanf("%d %d\n", &m, &q);

	for (int i = 0; i < m; ++i) {
		scanf("%s%n\n", movie[i], movie_len + i);
	}

	while (q--) {
		int dist = 1e9, ans = 0, len;
		scanf("%s%n\n", clip, &len);

		for (int i = 0; i < m; ++i) {
			int temp_len = movie_len[i];
			for (int j = 0; temp_len - j >= len; ++j) {
				int temp = ham_dist(movie[i] + j);
				if (temp < dist) {
					dist = temp;
					ans = i;
				}
			}
		}

		printf("%d\n", ans + 1);
	}

	return 0;
}
