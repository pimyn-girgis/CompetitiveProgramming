/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 1064 UVA
* Link    : https://onlinejudge.org/external/10/p1064.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

struct packet {

	bool operator<(const packet x) const{
		return this->start < x.start;
	}

	int num;
	int start;
	int end;
};

int n, m;
int message[6];
int order[5];
packet data[1005];
bool done[1005];

int solve() {
	memset(done, 0, m);
	int buff = 0, max_buff = 0;

	for (int i = 0; i < n; ++i) {

		int message_no = order[i];
		set<packet> fragment;
		int cur_en = 0;

		for (int j = 0; j < m; ++j) {

			if (!done[j]) {
				done[j] = true;
				buff += (data[j].end - data[j].start + 1);
			}

			if (data[j].num == message_no) {
				fragment.insert(data[j]);

				auto cur_frag = fragment.begin();

				while (!fragment.empty() && cur_frag->start == cur_en + 1) {
					cur_en = cur_frag->end;
					buff -= (cur_frag->end - cur_frag->start + 1);
					cur_frag = fragment.erase(fragment.begin());
				}

				if (message[message_no] == cur_en) {
					break;
				}
			}

			max_buff = max(buff, max_buff);
		}
	}

	return max_buff;
}

int main() {
	int tc = 0;

	while (scanf("%d %d\n", &n, &m),  n && m) {
		iota(order, order + 5, 0);

		for (int i = 0; i < n; ++i) {
			scanf("%d", message + i);
		}

		for (int i = 0; i < m; ++i) {
			auto &it = data[i];
			scanf("%d %d %d", &it.num, &it.start, &it.end); --it.num;
		}

		int buff = 1e9;
		do {
			buff = min(buff, solve());
		} while (next_permutation(order, order + n));

		printf("Case %d: %d\n\n", ++tc, buff);
	}

	return 0;
}
