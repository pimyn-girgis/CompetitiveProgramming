#include <bits/stdc++.h>
using namespace std;

int n, k, in1, Count , in2, upCount, total;
char board [1000][25];

int main()
{
	scanf("%d%d", &n, &k);
	upCount = Count = 0;
	total = n;
	memset(board, 0, sizeof(board));

	while(k--)
	{
		scanf("%d%d", &in1, &in2);
		scanf("%s%s", board[--in1], board[--in2]);
		if(!strcmp(board[in1], board[in2]))
		{
			strcpy(board[in1], "\0");
			strcpy(board[in2], "\0");
			total -= 2;
		}
	}

	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		{
			if(strcmp(board[i], "\0") && !strcmp(board[i], board[j]))
			{
				++Count;
				strcpy(board[i], "\0");
				strcpy(board[j], "\0");
				total -= 2;
			}
		}

	for(int i = 0; i < n; ++i)
		if(strcmp(board[i], "\0"))
			++upCount;

	if(upCount == total/2)
		Count += upCount;
	else
		Count += total == 2;

	printf("%d", Count);
	return 0;
}

