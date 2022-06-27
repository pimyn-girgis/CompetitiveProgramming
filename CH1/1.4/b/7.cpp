#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y;
	scanf("%d%d", &n, &x);
	n *= (1+x);
	while(x--)
	{
		scanf("%d", &y);
		n -= y;
	}
	printf("%d", n);
	return 0;
}

