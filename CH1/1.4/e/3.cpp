#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, x, y;
	scanf("%d", &t);
		for(int i = 1;i <= t;++i)
		{
			y = 0;
			scanf("%d", &n);
			while(n--)
			{
				scanf("%d", &x);
				if(x > y)
					y = x;
			}
			printf("Case %d: %d\n", i, y);
		}
	return 0;
}

