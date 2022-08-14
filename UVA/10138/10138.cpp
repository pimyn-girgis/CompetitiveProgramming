#include <bits/stdc++.h>
using namespace std;

int toll[24];
unordered_map <string, map< tuple< int, int, int, int> , bool > > record; //((license), (day, hour, minute, dist), enter)
//you can't use a pair instead of the tuple (hour, dist), since you need to sort chronologically
//you don't need the month __All dates will be within a single month.__

void solve()
{
	map <string, long double> payment;

	for(auto &u : record)
	{
		for(auto it = u.second.begin(); it != u.second.end(); ++it)
		{
			auto next = it;
			++next;

			if(next == u.second.end())
				break;

			if(it->second && !next->second)
			{
				if(payment.find(u.first) == payment.end())
					payment[u.first] = 200;
				payment[u.first] += toll[get<1>(it->first)] * abs(get<3>(it->first) - get<3>(next->first)) + 100;
				it = next;
			}
		}
	}

	for(auto &u : payment)
		printf("%s $%.2LF\n", u.first.c_str(), u.second / 100);
}

int main()
{
	int tc;
	scanf("%d\n\n", &tc);

	record.reserve(int(1e4));

	while(tc--)
	{
		for(auto &u : toll)
			scanf("%d ", &u);

		record.clear();

		char input[50];
		while(fgets(input, sizeof(input), stdin) && input[0] != '\n')
		{
			char license[25], state[10];
			int day, hour, minute, dist;
			sscanf(input, "%s %*d:%d:%d:%d %s %d", license, &day, &hour, &minute, state, &dist);
			record[license].insert(make_pair(make_tuple(day, hour, minute, dist), !strcmp(state, "enter")));
		}

		solve();

		if(tc) printf("\n");
	}

	return 0;
}
