#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,counter = 0;
	while(scanf("%d",&n) != EOF)
	{
	 	int x, l = 1000001, m = - l;
		while(n--)
		{
			scanf("%d", &x);
			l = min(l, x);
			m = max(m, x);
		}
		printf("Case %d: %d %d %d\n", ++counter, l, m, m - l);
	}
	return 0;
}

