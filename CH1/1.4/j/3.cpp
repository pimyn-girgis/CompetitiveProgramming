#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc, dur, mile, juice, calls, cost;
	char ans [20];
	scanf("%d", &tc);

	for(int i = 1; i <= tc; ++i)
	{
		dur = mile = juice = 0;
		scanf("%d", &calls);

		while(calls--)
		{
			scanf("%d", &dur);
			mile += dur/30 + 1;
			juice += dur/60 +1;
		}

		mile *= 10;
		juice *= 15;

		if(juice < mile)
			strcpy(ans, "Juice");
		else if(juice > mile)
			strcpy(ans, "Mile");
		else
			strcpy(ans, "Mile Juice");
		cost = min(juice, mile);
		printf("Case %d: %s %d\n", i, ans, cost);
	}
	return 0;
}

