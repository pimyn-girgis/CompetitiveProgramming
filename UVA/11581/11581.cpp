#include <bits/stdc++.h>
using namespace std;

char grid[3][4];

bool valid(int x){return x >= 0 && x <3;}
bool valid(int x, int y){return valid(x) && valid(y);}
int x[4] = {-1, -1, 1, 1};
int y[4] = {-1, 1, 1, -1};

char sumMod(int xpos, int ypos)
{
	int val = 0;
	for(int i=0;i<4;++i)
		if(valid(xpos+x[i], ypos+y[i]))
			val += grid[ypos+y[i]][xpos+x[i]] == '1';
	
	return val%2 + '0';
}

void solve()
{
	char Fgrid[3][4];
	memset(Fgrid, 0, sizeof(Fgrid));
	int ans = -1;
	while(1)
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				Fgrid[j][i] = sumMod(j, i);
		if(!memcmp(grid, Fgrid, sizeof(grid)))
			++ans;
		memcpy(grid, Fgrid, sizeof(grid));
	}
	printf("%d\n", ans);
}

int main()
{
	int ts;
	scanf("%d", &ts);
	while(ts--)
	{
		for(int i=0;i<3;++i) scanf("%s", grid[i]);
		solve();
	}
	return 0;
}
/*
8 111 111 111 111 110 000 110 000 000 110 001 101 101 010 101 111 000 111 000 000 000 101 000 101
*/