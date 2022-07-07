#include <bits/stdc++.h>
using namespace std;

int land[100][100];
int newland[100][100];
int n, r, c, k;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

bool valid(int row, int col){return row < r && row >= 0 && col < c && col >= 0;}

void output()
{
	for(int i=0;i<r;++i, printf("\n"))
		for(int j=0;j<c;++j)
			printf("%d%c",land[i][j], j==c-1? '\n' : ' ');
}

void battle()
{
	memcpy(newland, land, sizeof(land));
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			for(int k=0;k<4;++k)
			{
				int att = land[i][j];
				int row = i + y[k];
				int col = j + x[k];
				if(valid(row, col))
				{
					int def = land[row][col];
					if(att == def-1 || att == n-1 && !def)
						newland[row][col] = att;
				}
			}
	memcpy(land, newland, sizeof(land));
}

void input()
{
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			scanf("%d", &land[i][j]);
}

int main()
{
	while(scanf("%d %d %d %d", &n, &r, &c, &k) && n)
	{
		input();
		while(k--) battle();
		output();
	}
	return 0;
}