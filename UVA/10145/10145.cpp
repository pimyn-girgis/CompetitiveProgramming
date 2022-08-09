#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d\n\n", &tc);

	while (tc--)
	{
		char mode;
		int trid, item;
		unordered_set <int> blocked_trid;

		while(scanf("%c", &mode) && mode != '#')
		{
			scanf("%d %d\n", &trid, &item);
			//conflict : trid1 != trid2 && one lock is X
			if(blocked_trid.find(trid) != blocked_trid.end())
				printf("IGNORED");
			else
			{
			}
			printf("\n");
		}
	}
	return 0;
}
