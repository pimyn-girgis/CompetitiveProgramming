#include <bits/stdc++.h>
using namespace std;

int weight[1<<15];
int adj[1<<15][15];
int sum[1<<15];
int n, corners;

void init()
{
	for(int i=0;i<1<<15;++i)
		for(int j=0;j<15;++j)
			adj[i][j] = i ^ (1 << j);
}

int solve()
{
	memset(sum, 0, sizeof(sum));

	for(int i = 0;i < corners;++i)
		for(int j = 0;j < n;++j)
			sum[i] += weight[adj[i][j]];

	int ans = 0;

	for(int i = 0;i < corners; ++i)
		for(int j = 0;j < n;++j)
			ans = max(ans, sum[i] + sum[adj[i][j]]);

	return ans;
}

int main()
{
	init();
	while(scanf("%d", &n) != EOF)
	{
		corners = 1 << n;
		for(int i = 0;i < corners;++i)
			scanf("%d", &weight[i]);
		printf("%d\n", solve());
	}
	return 0;
}
