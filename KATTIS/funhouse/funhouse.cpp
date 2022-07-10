#include <bits/stdc++.h>
using namespace std;

char house[25][25];
int wid, len;
int dir; //{right, left, up, down}
int x, y;

bool isEnter(char c){return c == '*';}
void getEnter()
{
	for(int i=1;i<w-1;++i)
		if(isEnter(board[0][i]))
		{
			dir = 3;
			x = i;
			y = 0;
			return;
		}
		else if(isEnter(board[l-1][i]))
		{
			dir = 2;
			x = i;
			y = l-1;
			return;
		}
	for(int i=1;i<l-1;++i)
		if(isEnter(board[i][0]))
		{
			dir = 0;
			x = 0;
			y = i;
			return;
		}
		else if(isEnter(board[i][w-1]))
		{
			dir = 1;
			x = w-1;
			y = i;
			return;
		}
}

int main() 
{
	while(scanf("%d %d", &wid, &len) && (wid || len))
	{
		for(int i=0;i<len;++i)
			scanf("%s", house[i]);
	}
	return 0;
}
