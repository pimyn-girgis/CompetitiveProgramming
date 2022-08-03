#include <bits/stdc++.h>
using namespace std;

char need[] = "MARGIT";
int have[30];
int value[] = {1, 3, 2, 1, 1, 1};
char pizza[605];

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		memset(have, 0, sizeof(have));
		scanf("%s", pizza);

		for(auto &u : pizza)
			if(!u) break;
			else ++have[u - 'A'];

		int pizzaCount = 1e9;

		for(char c = 'A'; c <= 'Z'; ++c)
		{
			int pos = find(need, need + 6, c) - need;
			if(pos != 6) pizzaCount = min(pizzaCount, have[c - 'A']/value[pos]);
		}

		printf("%d\n", pizzaCount);
	}
	return 0;
}
