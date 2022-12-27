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

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

vector<vector<int>> adj(21);

int main()
{
	int fire, tc = 1;
	while(scanf("%d\n", &fire) != EOF)
	{
		for(auto &u : adj)
			u.clear();

		int from, to;
		while(scanf("%d %d\n", &from, &to), from && to)
		{
			--from, --to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		
		printf("CASE %d:\n", tc++);
	}
	return 0;
}
