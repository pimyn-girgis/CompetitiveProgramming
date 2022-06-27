#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, count = 0;
	scanf("%d", &t);
	while(t--)
	{
		int n, low = 0, high = 0, x, y;
		scanf("%d%d", &n, &y);
		while(--n)
		{
			scanf("%d", &x);
			if(x > y)
				++high;
			else if(x < y)
				++low;
			y = x;
		}
		++count;
		printf("Case %d: %d %d\n", count, high, low);
	}
	return 0;
}

