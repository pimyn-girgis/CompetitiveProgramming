#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d\n\n", &tc);

	while (tc--)
	{
		unordered_map <int, vector< pair<int, char> > >lock; //item, trid, mode
		unordered_set <int> blocked_trid;

		char mode;
		int trid, item;

		while(scanf("%c ", &mode), mode != '#')
		{
			bool denied = 0;
			scanf("%d %d\n", &trid, &item);

			if(blocked_trid.find(trid) != blocked_trid.end())
				printf("IGNORED\n");

			else
			{
				bool denied = 0;
				for(auto &u : lock[item])
					if((u.second == 'X' || mode == 'X') && trid != u.first)
						denied = 1, blocked_trid.insert(trid);

				if(!denied)
					lock[item].push_back(make_pair(trid, mode));

				printf("%s\n", denied? "DENIED" : "GRANTED");
			}
		}

		if(tc) printf("\n");
	}
	return 0;
}
