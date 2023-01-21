/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11550 UVA
* Link    : https://onlinejudge.org/external/115/p11550.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
	int tc;
	scanf("%d", &tc);
	int matrix[8][30];

	while(tc--)
	{
		map<int, int> edges;
		int num_of_vertices, num_of_edges;
		scanf("%d %d", &num_of_vertices, &num_of_edges);

		for (int i = 0 ; i < num_of_vertices ; ++i)
			for (int j = 0 ; j < num_of_edges ; ++j)
				scanf("%d", matrix[i] + j);

		bool yes = true;
		for (int i = 0; i < num_of_edges && yes ; ++i)
		{
			int first = 0, second = 0;
			for(int j = 0; j < num_of_vertices && yes; ++j)
			{
				if(!matrix[j][i])
					continue;

				if(first && second) yes = false;
				else if(first) second = j + 1;
				else first = j + 1;
			}

			if(edges.find(first) != edges.end() && edges[first] == second || !second)
				yes = false;
			else edges[first] = second;
		}

		printf("%s\n", yes? "Yes" : "No");
	}

	return 0;
}
