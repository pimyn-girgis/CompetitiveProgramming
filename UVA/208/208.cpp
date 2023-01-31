/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 208 UVA
* Link    : https://onlinejudge.org/external/2/p208.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> adj[21];
int dest, routes, visited, len = 1;
int route[21] {1};

void prune(int node = dest) { //marks all nodes that could get you to destination as visited
	//later I flip the values of visisted before I start dfs
	//This way, I never go to nodes that won't get me to dest
	visited |= (1 << node);
	for (auto u : adj[node]) {
		if (visited & (1 << u)) {
			continue;
		}
		prune(u);
	}

}

void solve(int node = 1) {
	if (node == dest) {
		++routes;
		for (int i = 0; i < len; ++i) {
			printf("%d%c", route[i], i == len - 1? '\n' : ' ');
		}
		return;
	}

	for (auto i : adj[node]) {
		if (!(visited & (1 << i))) {
			route[len++] = i; visited |= (1 << i);
			solve(i);
			--len; visited &= ~(1 << i);
		}
	}
}

int main() {

	int case_no = 1;
	while (scanf("%d", &dest) != EOF) {

		for (auto &u : adj) {
			u.clear();
		}

		routes = 0;
		visited = 0;

		int from, to;
		while (scanf("%d %d", &from, &to), from || to) {
			adj[from].insert(to);
			adj[to].insert(from);
		}

		prune();
		visited = ~visited | 2; //flipping bits, and marking 1 as visited

		printf("CASE %d:\n", case_no++);
		solve();
		printf("There are %d routes from the firestation to streetcorner %d.\n", routes, dest);
	}

	return 0;
}
