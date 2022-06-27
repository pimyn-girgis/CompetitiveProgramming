#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, x, n, r = 0, m = 0;
	char c [6];
	scanf("%d%d", &l, &x);
	while(x--)
	{
		scanf("%s%d", c, &n);
		if(!strcmp("enter", c))
		{
			if(n <= l - r)
				r += n;
			else
				++m;
		}
		else
			r -= n;
	}
	printf("%d", m);
	return 0;
}

