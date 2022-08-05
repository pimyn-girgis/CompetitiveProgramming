#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		int val;

		unordered_map <int, int> values;
		for(int i = 0; i < n; ++i) scanf("%d", &val), ++values[val];

		int ans = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", &val);
			if(values[val]) --values[val], --n;
			else ++ans;
		}

		printf("%dd\n", ans + n);
	}
	return 0;
}
