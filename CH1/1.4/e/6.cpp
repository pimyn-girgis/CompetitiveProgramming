#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, z = 1e9, i = 0, j;
	scanf("%d", &x);
	while(x--)
	{
		scanf("%d", &y);
		if(y < z)
		{
			z = y;
			j = i;
		}
		++i;
	}
	printf("%d", j);
	return 0;
}

