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
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>
using namespace std;


string master, driven;
char temp[105];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	while (cin >> master >> driven) {
		if (master.size() < driven.size()) {
			swap(master, driven);
		}

		int off_set;
		int ans = 1e9;

		for (off_set = -master.size(); off_set <= (int)master.size(); ++off_set) {
			bool solved = true;
			for (int i = 0; i < driven.size(); ++i) {
				int pos = i + off_set;
				if(pos < 0 || pos >= master.size()) {
					continue;
				}
				else if (master[pos] + driven[i] > '1' + '2') {
					solved = false;
				}
			}

			if (solved) {
				int temp = off_set < 0? master.size() - off_set : max(driven.size() + off_set, master.size());

				ans = min(ans, temp);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
