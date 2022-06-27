#include <bits/stdc++.h>
using namespace std;

int n, card[5][5], val, ans;
bool done[5][5], over;

void fix()
{
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			if(card[i][j] == val)
			{
				done[i][j] = 1;
				return;
			}
}
bool win()
{
	bool yes;
	for(int i = 0; i < 5; ++i) //rows
	{
		yes = 1;
		for(int j = 0; j < 5; ++j) 
			if(!done[i][j])
				yes = 0;
		if(yes) return 1;
	}

	for(int i = 0; i < 5; ++i) //columns
	{
		yes = 1;
		for(int j = 0; j < 5; ++j) 
			if(!done[j][i])
				yes = 0;
		if(yes) return 1;
	}
	yes = 1;
	for(int i = 0, j = 0; i < 5; ++i, ++j) //main diagonal
		if(!done[i][j])
			yes = 0;
	if(yes) return 1;

	yes = 1;
	for(int i = 0, j = 4;i < 5; ++i, --j) //antidiagonal
		if(!done[i][j])
			yes = 0;

	return yes;
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		memset(done, 0, sizeof(done));
		over = 0;
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 5; ++j)
				if(i != 2 || j != 2) scanf("%d", &card[i][j]);
		done[2][2] = 1;

		for(int i = 0; i < 75; ++i)
		{
			scanf("%d", &val);
			fix();
			if(win() && !over)
			{
				ans = i + 1;
				over = 1;
			}
		}
		printf("BINGO after %d numbers announced\n", ans);
	}
	return 0;
}

