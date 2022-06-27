#include <bits/stdc++.h>
using namespace std;

int main()
{
	char c[10][101];
	int a[10];
	int t;
	int j = 0;
	scanf("%d", &t);
	while(t--)
	{
		++j;
		int n = 0;
		for(int i = 0; i < 10; ++i)
		{
			scanf("%s%d", c[i], &a[i]);
			n = max(n, a[i]);
		}
		printf("Case #%d:\n", j);
		for(int i = 0; i < 10; ++i)
			if(n == a[i])
				printf("%s\n", c[i]);
	}
	return 0;
}
