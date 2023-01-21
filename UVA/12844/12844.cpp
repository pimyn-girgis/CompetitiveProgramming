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

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
using namespace std;


int main() {

	int arr[10]; int w[5];
	int tc; scanf("%d", &tc);

	for (int case_no = 1; case_no <= tc; ++case_no) {

		for (auto &u : arr) {
			scanf("%d%*c", &u);
		}

		int sum = accumulate(arr, arr + 10, 0) / 4;
		w[2] = sum - (arr[9] + arr[0]);
		w[0] = arr[1] - w[2];
		w[1] = arr[0] - w[0];
		w[4] = arr[8] - w[2];
		w[3] = arr[9] - w[4];

		printf("Case %d:", case_no);
		for (auto u : w) {
			printf(" %d", u);
		}
		printf("\n");
	}

	return 0;
}
