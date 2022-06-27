//minesweeper uva 10189
#include <bits/stdc++.h>
using namespace std;

char board[100][110], ans[100][105];
int m, n, sum, ts = 0;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, -1, 0, 1, -1, 0, -1, 1};

bool valid(int x, int y) {return 0 <= x && x < m && 0 <= y && y < n;}
void solve()
{
	printf("Field #%d:\n", ts);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(board[i][j] == '*')
			{
				ans[i][j] = '*';
				for(int k = 0; k < 8; ++k)
				{
					int x = dx[k] + j, y = dy[k] + i; //pay attention to x and y
					if(valid(x, y) && board[y][x] != '*')
						++ans[y][x];
				}
			}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}

int main()
{	scanf("%d%d", &n, &m);
	while(m || n)
	{
		memset(ans, '0', sizeof(ans));
		for(int i = 0; i < n; ++i)
			scanf("%s", board[i]);
		++ts;
		solve();

		scanf("%d%d", &n, &m);
		if(m || n)
			printf("\n");
	}
}