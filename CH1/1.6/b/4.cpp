#include <bits/stdc++.h>
using namespace std;

char board[8][9], input[100], *ptr, occupied[8][9];
bool attacked[8][8];
int sum;

bool valid(int x){return 0 <= x && x < 8;}
void attack(int x, int y){if (valid(x) && valid(y)) attacked[x][y] = 1;}

void pawn(int x, int y, bool black)
{
	int dif = -1 + 2 * black;
	attack(x+dif, y-1);
	attack(x+dif, y+1);
}

void knight(int x, int y)
{
	int d_x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
	int d_y[8] = {1, -1, 1, -1, 2, -2, 2, -2};
	for(int i = 0; i < 8; ++i)
			attack(x + d_x[i],y + d_y[i]);
}

void bishopRook(int x, int y, bool limit, int d_x[], int d_y[])
{
	int xtemp = x, ytemp = y;
	for(int i = 0; i < 4; ++i)
	{
		do
		{
			x += d_x[i];
			y += d_y[i];
			if(isalpha(occupied[x][y])) break;
			attack(x, y);
		}while(valid(x) && valid(y) && !limit);
		y = ytemp; x = xtemp;
	}
}
void bishop(int x, int y, bool limit)
{
	int d_x[4] = {1, 1, -1, -1};
	int d_y[4] = {1, -1, 1, -1};
	bishopRook(x, y, limit, d_x, d_y);
}

void rook(int x, int y, bool limit)
{
	int d_x[4] = {1, -1, 0, 0};
	int d_y[4] = {0, 0, 1, -1};
	bishopRook(x, y, limit, d_x, d_y);
}

void queen(int x, int y)
{
	rook(x, y, 0);
	bishop(x, y, 0);
}

void king(int x, int y)
{
	rook(x, y, 1);
	bishop(x, y, 1);
}

void ReadMap()
{
	for(int i = 0; i < 8; ++i)
		{
			for(int j = 0, l, prev = 0; board[i][j]; ++j)
			{
				if(isdigit(board[i][j]))
				{
					l = board[i][j] - '0';
					for(int k = 0; k < l; ++k)
						occupied[i][j+k+prev] = '0';
					prev += l - 1;
				}
			}
		}
	for(int i = 0; i < 8; ++i)
		for(int j = 0, k = 0; j < 8; ++j)
			if(occupied[i][j] - '0')
				for(; board[i][k]; ++k)
					if(isalpha(board[i][k]))
					{
						attacked[i][j] = 1;
						occupied[i][j] = board[i][k] == 'p'? 'p' : toupper(board[i][k]);
						++k;
						break;
					}
}
int main()
{
	while(scanf("%s", input) != EOF)
	{
		sum = 64;

		for(int i = 0; i < 8; ++i)
		{
			memset(occupied[i], '1', 8);
			memset(attacked[i], 0, 8);
		}

		ptr = strtok(input, "/");
		for(int i = 0; i < 8;++i)
		{
			strcpy(board[i], ptr);
			ptr = strtok(nullptr, "/");
		}
		ReadMap();

		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				if(occupied[i][j] == 'B')
					bishop(i, j, 0);
				else if(occupied[i][j] == 'R')
					rook(i, j, 0);
				else if(occupied[i][j] == 'K')
					king(i, j);
				else if(occupied[i][j] == 'Q')
					queen(i, j);
				else if(occupied[i][j] == 'N')
					knight(i, j);
				else if(occupied[i][j] == 'p')
					pawn(i, j, 1);
				else if(occupied[i][j] == 'P')
					pawn(i, j, 0);

		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				sum -= attacked[i][j];
		printf("%d\n",sum);
	}
		return 0;
}