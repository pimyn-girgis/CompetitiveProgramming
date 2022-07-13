#include <bits/stdc++.h>
using namespace std;

bool sml[10][10], lrg[10][10], comp[10][10];
int m, n;

void init()
{
	memset(sml, 0, sizeof(sml));
	memset(lrg, 0, sizeof(lrg));
}

void fix()
{
	for(int j=0;j<m;++j)
	{
		for(int i=0;i<m;++i)
			if(sml[i][0]) goto label;

			for(int a=0;a<m;++a)
				for(int b=0;b<m-1;++b)
					swap(sml[a][b] ,sml[a][b+1]);
	}
label:
	for(int j=0;j<m;++j)
	{
		for(int i=0;i<m;++i)
			if(sml[0][i]) return;

			for(int a=0;a<m-1;++a)
				for(int b=0;b<m;++b)
					swap(sml[a][b] ,sml[a+1][b]);
	}
}

bool input()
{
	int invalid = 0;
	char in[15];
	for(int i=0;i<n;++i)
		{
			scanf("%s", in);
			for(int j=0;in[j];++j)
			invalid += (lrg[i][j] = in[j] == '*');
		}
		for(int i=0;i<m;++i)
		{
			scanf("%s", in);
			for(int j=0;in[j];++j)
			invalid -= 2 * (sml[i][j] = in[j] == '*');
		}
	return !invalid;
}

bool valid(int x){return x < n && x >= 0;}
bool valid(int x, int y){return valid(x) && valid(y);}

bool Set(int a, int b)
{
	for(int x=a;x<a+m;++x)
		for(int y=b;y<b+m;++y)
			if(valid(x, y) && sml[x-a][y-b]) 
			{
				if(comp[x][y]) return 0;
				comp[x][y] = 1;
			}
	return 1;
}

bool test(int i, int j, int a, int b)
{
	memset(comp, 0, sizeof(comp));
	if(!(Set(i, j) && Set(a, b))) return 0;
	return (!memcmp(lrg, comp, sizeof(lrg)));
}

bool solve()
{
	fix();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int a=0;a<n;++a)
				for(int b=0;b<n;++b)
					if(test(i, j, a, b))
						return 1;
	return 0;
}

int main()
{
	while(scanf("%d %d", &n, &m) && (m || n))
	{
		init();
		printf("%d\n", (input() && solve()));
	}
	return 0;
}
