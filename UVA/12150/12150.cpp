#include <bits/stdc++.h>
using namespace std;

int n, c[1005], p[1005], pos[1005];
bool exist[1005];
bool valid(int pos){return pos < n && pos >= 0;}
bool solve()
{
	for(int i=0;i<n;++i)
	{
		int newpos = i+p[i];
		if(!valid(newpos)) return 0;
		exist[newpos] = 1;
		pos[newpos] = c[i];
	}
	return !(find(exist, exist+n, 0) - (exist+n));
}
void input(){for(int i=0;i<n;++i) scanf("%d %d", c+i, p+i);}
void init(){memset(exist, 0, n*sizeof(bool));}
void grid(){for(int i=0;i<n;++i)printf("%s%d",i? " " : "", pos[i]);}
int main()
{
	while(scanf("%d", &n) && n)
	{
		init();
		input();
		if(solve()) grid();
		else printf("-1");
		printf("\n");
	}
	return 0;
}