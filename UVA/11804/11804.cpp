/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11804 UVA
* Link    : https://onlinejudge.org/external/118/p11804.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

struct player {

	bool operator<(player &x) {
		return this->name < x.name;
	}

	string name;
	int atk;
	int def;
};

int max_atk, total_def, max_def;
player players[10];
player temp_attack[5];
player attack[5], defense[5];

void solve(int pos = 0, int st = 0, int taken = 0) {

	if (pos == 5) {
		int atk = accumulate(temp_attack, temp_attack + 5, 0, [](const int &a, const player &y){return a + y.atk;});
		int def = total_def - accumulate(temp_attack, temp_attack + 5, 0, [](const int &a, const player &y){return a + y.def;});
		if (atk > max_atk || (atk == max_atk && def > max_def)) {
			max_atk = atk; max_def = def;
			copy(temp_attack, temp_attack + 5, attack);
			int j = 0;

			for (int i = 0; i < 10; ++i) {
				if (!(taken & (1 << i))) {
					defense[j++] = players[i];
				}
			}

		}

		return;
	}

	for (int i = st; i < 10; ++i) {
		taken |= (1 << i);
		temp_attack[pos] = players[i];
		solve(pos + 1, i + 1, taken);
		taken &= ~(1 << i);
	}
}

void output(player *members) {
	printf("(");
	for (int i =0; i < 5; ++i) {
		printf("%s%s", members[i].name.c_str(), i == 4? ")" : ", ");
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d\n", &tc);

	char input[25];

	for (int test = 1; test <= tc; ++test) {
		for (int i = 0; i < 10; ++i) {
			scanf("%s %d %d", input, &players[i].atk, &players[i].def);
			players[i].name = input;
		}

		max_atk = 0; max_def = 0;
		total_def = accumulate(players, players + 10, 0, [](int a, const player &x){return a + x.def;});
		sort(players, players + 10);

		solve();

		printf("Case %d:\n", test);
		output(attack);
		output(defense);
	}

	return 0;
}
