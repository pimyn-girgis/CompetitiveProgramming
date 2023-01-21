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
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cubic_root;

void get_cubes() {
	cubic_root.reserve(1000);
	for (int i = 2; i <= 200; ++i) {
		cubic_root[i * i * i] = i;
	}
}

bool is_cube(int n) {
	return cubic_root.find(n) != cubic_root.end();
}

struct four {
	int arr[4];
};

int main() {
	get_cubes();
	four output[223];
	int index = -1;

	for (int a = 2; a <= 200; ++a) {
		for (int b = 2; b <= a; ++b) {
			for (int c = 2; c <= b; ++c) {
				int val = a * a * a + b * b * b + c * c * c;
				if (is_cube(val)) {
					int arr[4] = {cubic_root[val], c, b, a};
					memcpy(output[++index].arr, arr, sizeof(arr));
				}
			}
		}
	}

	int k = 0;
	sort(output, output + 223, [](four &x, four &y){return memcmp(&x, &y, 4 * sizeof(int)) < 0;});

	for (auto u = &output[0]; u != &output[223]; ++u) {
		printf("Cube = %d, Triple = (", u[0].arr[0]);
		for (int i = 1; i <= 3; ++i) {
			printf("%d%c", u[0].arr[i], i == 3? ')' : ',');
		}
		printf("\n");
	}

	return 0;
}
