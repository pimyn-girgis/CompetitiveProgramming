#include <bits/stdc++.h>
using namespace std;

char board[110][110];

int main()
{
	int x = 0;
	memset(board, 0, sizeof(board));
	for(int i = 0; i < 10; ++i)
		scanf("%s", board[x++]);
	return 0;
}

