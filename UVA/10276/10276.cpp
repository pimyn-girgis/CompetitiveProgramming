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
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

bool is_square(int val) {
	int sqr = sqrt(val);
	return val == sqr * sqr;
}

int arr[51];
int ans;
int n;

void place(int val) {
	for (int i = 0; i < n; ++i) {
		if (!arr[i] || is_square(arr[i] + val)) {
			arr[i] = val; ++ans;
			place(val + 1);
			break;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		memset(arr, 0, sizeof(arr)); ans = 0;
		scanf("%d", &n);
		place(1);
		printf("%d\n", ans);
	}

	return 0;
}
