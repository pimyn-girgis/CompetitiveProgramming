#include <bits/stdc++.h>
using namespace std;

bool tree[105][105];
int ans[105][105];
int r, c, maxVal;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x,int y){return x >= 0 && x < r && y >= 0 && y < c;}

void solve()
{
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			if(tree[i][j])
			{
				int val = 100;
				for(int k=0;k<4;++k)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					val = valid(x, y)? min(val, ans[i+dx[k]][j+dy[k]]) : 0;
				}
				ans[i][j] = val +1;
			}
}

void output()
{
	int dots = 0;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			dots = max(dots, ans[i][j]);
	if(dots < 10)
	{
		for(int i=0;i<r;++i, printf("\n"))
			for(int j=0;j<c;++j)
				if(ans[i][j]) printf(".%d", ans[i][j]);
				else printf("..");
	}
	else
	{
		for(int i=0;i<r;++i, printf("\n"))
			for(int j=0;j<c;++j)
				if(ans[i][j] >= 10) printf(".%d", ans[i][j]);
				else if(ans[i][j] < 10 && ans[i][j] > 0) printf("..%d", ans[i][j]);
				else printf("...");
	}
}

void init()
{
	memset(ans, 0, sizeof(ans));
	maxVal = min(r, c) + 2;
}

int main() 
{
	char in[105];
	scanf("%d %d", &r, &c);
	init();
	for(int i=0;i<r;++i)
	{
		scanf("%s", in);
		for(int j=0;in[j];++j)
		tree[i][j] = in[j] == 'T';
	}
	while(maxVal--)
		solve();
	output();
	return 0;
}
