#include <bits/stdc++.h>
using namespace std;

int ts, x, o;
bool valid;
char board[3][4];
bool win[3];

bool rows(char xo)
{
	memset(win, 1, 3);
	for(int i=0;i<3;++i)           //rows
	{
		for(int j=0;j<3;++j)
		{
			if(board[i][j] != xo)
			win[i] = 0;
		}
		if(win[i]) return 1;
	}
	return 0;
}
bool columns(char xo)
{
	memset(win, 1, 3);
	for(int i=0;i<3;++i)           //columns
	{
		for(int j=0;j<3;++j)
		{
			if(board[j][i] != xo)
				win[i] = 0;
		}
		if(win[i]) return 1;
	}
	return 0;
}
bool diagonal(char xo)
{
	for(int i = 0, j = 0;i < 3; ++j,++i)
		if(board[i][j] != xo)
			return 0;
	return 1;
}
bool antidiagonal(char xo)
{
	for(int i = 0, j = 2; i < 3; ++i, --j)
		if(board[i][j] != xo)
			return 0;
	return 1;
}

bool won(char xo){return diagonal(xo) || antidiagonal(xo) || columns(xo) || rows(xo);}

int main()
{
	scanf("%d", &ts);
	while(ts--)
	{
		valid = 1;
		x = o = 0;
		for(int i = 0; i < 3; ++i)
		{
			scanf("%s", board[i]);
			for(int j = 0;board[i][j]; ++j)
				if(board[i][j] == 'X')
					++x;
				else if(board[i][j] == 'O')
					++o;
		}
		if(x != o && x != o + 1 || won('O') && won('X') || won('O') && x != o || won('X') && x != o + 1)
			valid = 0;
		printf("%s\n", valid? "yes" : "no");
	}
	return 0;
}

