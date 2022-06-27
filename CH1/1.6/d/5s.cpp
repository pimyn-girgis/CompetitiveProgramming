#include <bits/stdc++.h>
using namespace std;

struct player
{
	bool map[30][30];
	int ships;
};
int ts, w, h, n, x, y;
bool turn, done;
player arr[2];

void attack()
{
	//printf("turn: %d point: %d\n", turn, arr[turn].map[y][x]);
	if(done)
		return;
	if(arr[turn].map[y][x])
	{
		arr[turn].map[y][x] = 0;
		--arr[turn].ships;
		if(!arr[turn].ships)
			done = turn = !turn;
	}
	else
	{
		turn = !turn;
		done = turn && !arr[0].ships && !arr[0].ships;
	}
}
int main()
{
	char line[50];
	scanf("%d", &ts);
	while (ts--)
	{
		for(int i = 0; i < 2; ++i)
		{
			memset(arr[i].map, 0, sizeof(arr[i].map));
			arr[i].ships = 0;
		}
		scanf("%d%d%d", &w, &h, &n);
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < h; ++j)
			{
				scanf("%s", line);
				for(int k = 0; line[k]; ++k)
					if(line[k] == '#')
					{
						arr[i].map[j][k] = 1;
						++arr[i].ships;
					}
			}
		turn = 1; //1 p1, 0 p2
		done = 0;
		while(n--)
		{
			scanf("%d%d", &x, &y);
			y = h - y - 1;
			attack();
		}
		if(!arr[0].ships && !arr[1].ships || arr[0].ships && arr[1].ships)
			printf("draw\n");
		else
			printf("player %s wins\n", arr[0].ships? "one" : "two");
	}
	return 0;
}

/*
	for(int k = 0; k < 2; ++k)
		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
				printf("%d", arr[k].map[i][j]);
			printf("\n");
		}
*/