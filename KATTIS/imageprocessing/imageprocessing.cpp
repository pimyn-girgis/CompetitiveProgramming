#include <bits/stdc++.h>
using namespace std;

int kernel[25][25];
int img[25][25];
int ans[25][25];
int h, w, n, m, height, width;

void input()
{
	scanf("%d %d %d %d", &h, &w, &n, &m);

	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j)
			scanf("%d", &img[i][j]);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d", &kernel[n-i][m-j]);
}

void solve()
{
	memset(ans, 0, sizeof(ans));
	height = h - n + 1;
	width = w - m + 1;

	for(int i=0;i<height;++i)
		for(int j=0;j<width;++j)
			for(int k=0;k<n;++k)
				for(int x=0;x<m;++x)
					ans[i][j] += kernel[k][x] * img[i+k][j+x];
}

void output()
{
	for(int i=0;i<height;++i, printf("\n"))
		for(int j=0;j<width;++j)
			printf(j? " %d" : "%d", ans[i][j]);
}

int main() 
{
	input();
	solve();
	output();
	return 0;
}