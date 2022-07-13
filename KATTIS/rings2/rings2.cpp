#include <bits/stdc++.h>
using namespace std;

bool tree[105][105];
int ans[105][105];
int r, c;

void solve()
{
	memset(ans, 0, sizeof(ans));
	int maxVal = min(r, c);
	maxVal += maxVal%2;

	for(int i=1;i<maxVal;++i)
	{
		for(int j=0;j<r;++j)
		{
			for(int k=0;k<c;++k)
			{
			}
		}
	}
}

void output()
{
}

int main() 
{
	char in[105];
	scanf("%d %d", &r, &c);
	for(int i=0;i<r;++i)
	{
		scanf("%s", in)
		for(int j=0;in[j];++j)
		tree[i][j] = in[j] == 'T';
		solve();
		output();
	}
	return 0;
}
