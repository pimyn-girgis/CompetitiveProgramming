#include <bits/stdc++.h>
using namespace std;

char house[25][25];
int w, l, dir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
//			 r, d, l, u
int y, x;

void getInfo()
{
	for(int i=0;i<l;++i)
		for(int j=0;j<w;++j)
			if(house[i][j] == '*')
			{
				y = i;
				x = j;
				if(!j) dir = 0;
				else if(!i) dir = 1;
				else if(j == w-1) dir = 2;
				else dir = 3;
			}
}

void solve()
{
	getInfo();

	while(1)
	{
		y += dy[dir];
		x += dx[dir];
		char &comp = house[y][x];

		if(comp == '/')
		{
			if(dir == 0) dir = 3;
			else if(dir == 1) dir = 2;
			else if(dir == 2) dir = 1;
			else if(dir == 3) dir = 0;
		}
		else if(comp == '\\')
		{
			if(dir == 0) dir = 1;
			else if(dir == 1) dir = 0;
			else if(dir == 2) dir = 3;
			else if(dir == 3) dir = 2;
		}
		else if(comp == 'x')
		{
			comp = '&';
			return;
		}
	}
}

int main()
{
	int k = 0;
	while(scanf("%d %d", &w, &l) && (w || l))
	{
		for(int i=0;i<l;++i) scanf("%s", house[i]);
		solve();
		printf("HOUSE %d\n", ++k);
		for(int i=0;i<l;++i) printf("%s\n", house[i]);
	}
	return 0;
}
