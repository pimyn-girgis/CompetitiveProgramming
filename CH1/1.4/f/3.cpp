#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int m = -1e9, x = -1e9, y = -1e9;
		while(n--)
		{
			if(y < x)
			y = x;
			scanf("%d", &x);
			m = max(y - x, m);
		}
		printf("%d\n", m);
	}
	return 0;
}

