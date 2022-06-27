#include <bits/stdc++.h>
using namespace std;

int ts, a, b, c;

int main()
{
	int move[100][2], pos, roll, k;
	int player[1000000];
	bool win;
	scanf("%d", &ts);
	while (ts--)
	{
		k = 0;
		win = 0;
		scanf("%d %d %d", &a, &b, &c);
		for(int i = 0; i < a; ++i)
			player[i] = 1;
		for(int i = 0; i < b; ++i)
			scanf("%d %d", &move[i][0], &move[i][1]);
		while(c--)
		{
			k %= a;
			pos = player[k];
			scanf("%d", &roll);
			if(!win)
			{
				pos += roll;
				for(int i = 0; i < b; ++i)
					if(move[i][0] == pos)
					{
						pos = move[i][1];
						break;
					}
				if(pos > 100)
					pos = 100;
				player[k++] = pos;
				if(pos == 100)
					win = 1;
			}
		}
			  for(int i = 1; i <= a; ++i)
			printf("Position of player %d is %d.\n", i, player[i-1]);
	}
	return 0;
}

