#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, c, x, y, sum;
	while(scanf("%d", &a) && a)
	{
		sum = 0;
		y = a;
		scanf("%d", &c);
		while(c--)
		{
			scanf("%d", &x);	
			if(x < y)
				sum += y - x;
			y = x;
		}
		printf("%d\n", sum);
	}
	return 0;
}

