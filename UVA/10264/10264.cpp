#include <bits/stdc++.h>
using namespace std;

int weight[1<<15];
int sum[1<<15];
int n, corners;

int solve()
{
	memset(sum, 0, sizeof(sum));

	for(int i = 0;i < corners;++i)
		for(int j = 0;j < n;++j)
			sum[i] += weight[i ^ (1 << j)];

	int ans = 0;

	for(int i = 0;i < corners; ++i)
		for(int j = 0;j < n;++j)
			ans = max(ans, sum[i] + sum[i ^ (1 << j)]);

	return ans;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		corners = 1 << n;
		for(int i = 0;i < corners;++i)
			scanf("%d", &weight[i]);
		printf("%d\n", solve());
	}
	return 0;
}
