#include <bits/stdc++.h>
using namespace std;

char color[10], white[1000], black[1000], piece[8][8], first = '.', second = ':';

void fixRows(char *arr, bool blk)
{
	if(islower(arr[0]))
		piece[7 - (arr[1] - '1')][arr[0] - 'a'] = blk? 'p' : 'P';
	for(int i = 0; arr[i+2] ; ++i)
	{
		if(arr[i] == ',') arr[i] = 'P';
		if((isupper(arr[i])) && isdigit(arr[i+2]))
			piece[7 - (arr[i+2] - '1')][arr[i+1] - 'a'] = blk? tolower(arr[i]) : arr[i];
	}
}

void solve()
{
	for(int i = 0; i < 17; ++i)
	{
		if(i%2)
		{
			swap(first, second);
			printf("|");
			for(int j = 0; j < 8; ++j)
			{
				for(int k = 1; k <= 3; ++k)
				{
					if(k%2 || !piece[i/2][j])
                    {
                        if(first || second)
				    		printf("%c", j%2? first : second);
                    }
					else if(piece[i/2][j])
						printf("%c", piece[i/2][j]);
				}
				printf("|");
			}
		}
		else
			printf("+---+---+---+---+---+---+---+---+");
		printf("\n");
	}
}

int main()
{
	memset(piece, 0, sizeof(piece));
	if(scanf("%s%s", color, white) != EOF)
	{
		if(!strcmp(white , "Black:"))
			scanf("%s", black);
		else if(scanf("%s", color) != EOF)
			scanf("%s", black);
	}
	fixRows(white, 0);
	fixRows(black, 1);
	solve();
	return 0;
}