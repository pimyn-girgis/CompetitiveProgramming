#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, k;
	char c [20];
	scanf("%d", &t);
	while(t--)
	{
		int x = 0;
		scanf("%d", &n);
		vector<int> v (n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", c);
			if(!strcmp(c, "LEFT"))
				v[i] = -1;
			else if(!strcmp(c, "RIGHT"))
				v[i] = 1;
			else
			{
				scanf("%s%d", c, &k);
				v[i] = v[--k];
			}
		}
		k = 0;
		for(int &u : v)
			k += u;
		printf("%d\n", k);
	}
	return 0;
}

