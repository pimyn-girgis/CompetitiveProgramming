#include <bits/stdc++.h>
using namespace std;

int main()
{
	char card[52][5];
	int ts, y, count, val, begin;
	scanf("%d", &ts);

	for(int i = 1; i <= ts; ++i)
	{
		y = count = 0; begin = 25;
		for(int j = 0; j < 52; ++j)
			scanf("%s", card[52 - j - 1]);
		for(int j = 0; j < 3; ++j)
		{
			if(isdigit(card[begin][0]))
				val = card[begin][0] - '0';
			else
				val = 10;
			y += val;
			begin += (11 - val);
			count += (11 - val);
		}
		y = 52 - y - count;
		printf("Case %d: %s\n", i, y < 25? card[y] : card[y+count]);
	}
	return 0;
}

