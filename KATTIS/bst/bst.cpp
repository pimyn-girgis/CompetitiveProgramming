//https://open.kattis.com/problems/bst
#include <bits/stdc++.h>
using namespace std;

int dist[300005];

int main() 
{
	int n;
	scanf("%d", &n);

	set <int> bst;

	long long unsigned int c = 0;
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);

		auto cur = bst.insert(val).first;

		int depth = 0;

		if(i)
		{
			if(cur != bst.begin())
			{
				auto prev = cur;
				depth = dist[*--prev] + 1;
			}

			if(cur != bst.end())
			{
				auto next = cur;
				if(++next != bst.end())
					depth = max(dist[*next] + 1, depth);
			}
		}

		dist[val] = depth;
			printf("%llu\n", c += depth);
	}

	return 0;
}
