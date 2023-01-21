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
using namespace std;

int k;
int arr[15];
vector<int> vec;

void pick(int n, int i) {
	if (vec.size() == 6) {
		for (int i = 0; i < 6; ++i) {
			printf("%d%c", vec[i], i == 6 - 1? '\n' : ' ');
		}
		return;
	}

	for (; i < k; ++i) {
		vec.push_back(arr[i]);
		pick(n - 1, i + 1);
		vec.pop_back();
	}
}

int main() {
	scanf("%d ", &k);
	while (k) {
		for (int i = 0; i < k; ++i) {
			scanf("%d%*c", arr + i);
		}

		pick(6, 0);

		scanf("%d ", &k);
		if(k) printf("\n");
	}
	return 0;
}

