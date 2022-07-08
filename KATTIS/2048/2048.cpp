#include <bits/stdc++.h>
using namespace std;

int board[4][4];
int temp[4][4];

void rotate(int rot)
{
	if(rot == 4) return;

	while(rot--)
	{
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				temp[3-i][j] = board[j][i];
		memcpy(board, temp, sizeof(board));
	}
}

void input()
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			scanf("%d", &board[i][j]);
}

void fix()
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(!board[i][j])
				for(int k=j+1;k<4;++k)
					if(board[i][k])
					{
						swap(board[i][j], board[i][k]);
						break;
					}
}

void solve()
{
	fix();

	for(int i=0;i<4;++i)
		for(int j=0;j<3;++j)
			for(int k=j+1;k<4;++k)
				if(board[i][j] == board[i][k])
				{
					board[i][j] *= 2;
					board[i][k] = 0;
					break;
				}
				else if(board[i][k]) break;

	fix();
}

void output()
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			printf("%d%c", board[i][j], j<3? ' ' : '\n');
}

int main() 
{
	input();

	int rot;
	scanf("%d", &rot);
	rotate(rot);
	solve();
	rotate(4-rot);
	output();
	return 0;
}
