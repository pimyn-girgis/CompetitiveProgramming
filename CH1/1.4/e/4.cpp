#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y, c = 0;
	while(scanf("%d", &n))
	{
		if(n == 0)
			return 0;
		y = 0;
		while(n--)
		{
			scanf("%d", &x);
			if(!x)
				--y;
			else
				++y;
		}
		printf("Case %d: %d\n", ++c, y);
	}
	return 0;
}

