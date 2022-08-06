#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for(int test = 1; test <= tc; ++test)
	{
		set <int> stamps[50];
		map <int, int> freq;

		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			int m;
			scanf("%d", &m);

			int val;
			while(m--)
			{
				scanf("%d", &val);
				if(stamps[i].insert(val).second)
					++freq[val];
			}
		}

		for(auto &u : freq)
			if(u.second > 1)
				for(int i = 0; i < n; ++i)
					stamps[i].erase(u.first);

		int sum = 0;
		for(int i = 0; i < n; ++i)
			if(stamps[i].size())
				sum += stamps[i].size();

		printf("Case %d:", test);
		if(!sum)
			for(int i = 0; i < n; ++i)
				printf(" %f%%", 100.0l/n);
		else
			for(int i = 0; i < n; ++i)
				printf(" %Lf%%", 100.0l * stamps[i].size()/sum);

		printf("\n");
	}
	return 0;
}
