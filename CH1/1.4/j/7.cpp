#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts, n, m, k[30], req[10][30], price[10], tickets[30], sum, minVal;
	scanf("%d", &ts);

	while(ts--)
	{
		sum = 0;
		scanf("%d%d", &n, &m);
		for(int i =  0; i < n; ++i)
		{
			scanf("%d", &k[i]);

			for(int j = 0; j < k[i]; ++j)
				scanf("%d", &req[i][j]);
			scanf("%d", &price[i]);
		}
		for(int i = 0; i < m; ++i)
			scanf("%d", &tickets[i]);

		for(int i = 0; i < n; ++i)
		{
			minVal = 1e9;
			for(int j = 0; j < k[i]; ++j)
				minVal = minVal < tickets[req[i][j]-1]? minVal : tickets[req[i][j]-1];
				sum += minVal * price[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}

