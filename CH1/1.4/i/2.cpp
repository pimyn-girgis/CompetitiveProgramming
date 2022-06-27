#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, b, h, w, p, a, m;
	while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF)
	{
		m = 1e9;
		while(h--)
		{
			scanf("%d", &p);
			for(int i = 0; i < w; ++i)
			{
				scanf("%d", &a);
				if(a >= n && p * n <= b)
					m = min(m, p*n);
			}
		}
		if(m != 1e9)
			printf("%d\n", m);
		else
			printf("stay home\n");
	}
	return 0;
}

