#include <bits/stdc++.h>
using namespace std;

double price(int p, int a, int b, int c, int d, int k)
{
	return p * (sin(a * k + b)+cos(c * k + d) + 2);
}
int main()
{
	int a, b, c, d, p, n;
	while(scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n) != EOF)
	{
		double x = 0, y = -1e9, z=-1e9;
		for(int i = 1; i <= n ; ++i)
		{
			y = price(p, a, b, c, d, i);
			if(z < y)
				z = y;
			x = max(x, z - y);
		}
		printf("%f\n", x);
	}
	return 0;
}

