#include <bits/stdc++.h>
using namespace std;

int main()
{
	int b, n, x, y, z;
	while(scanf("%d%d", &b, &n))
	{
		if(!b)
			return 0;
		bool can = 1;
		vector <int> v (b);
		for(auto &u : v)
			scanf("%d", &u);
		while(n--)
		{
				scanf("%d%d%d", &x, &y, &z);
				v[x-1] -= z;
				v[y-1] += z;
		}
		for(auto &u : v)
			if(u < 0)
				can = 0;
		if(!can)
			printf("N\n");
		else
			printf("S\n");
	}

	return 0;
}

