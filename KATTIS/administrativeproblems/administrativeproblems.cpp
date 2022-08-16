//https://open.kattis.com/problems/administrativeproblems
#include <bits/stdc++.h>
using namespace std;

unordered_map <string, tuple<int, int, int> > car; //name,,,,catalog, pickup, perKilo
unordered_map <string, string> rent;
unordered_map <string, int> cost;
set <string> spyList;
set <string> inconsistent;

void pickup(char *spy)
{
	char carName[50];
	scanf("%s\n", carName);

	if(rent.find(spy) != rent.end())
		inconsistent.insert(spy);

	rent[spy] = carName, cost[spy] += get<1>(car[carName]);
}

void returnCar(char *spy)
{
	int dist;
	scanf("%d\n", &dist);

	if(rent.find(spy) == rent.end())
		inconsistent.insert(spy);

	else
		cost[spy] += dist * get<2>(car[rent[spy]]), rent.erase(spy);
}

void accident(char *spy)
{
	int severity;
	scanf("%d\n", &severity);

	if(rent.find(spy) == rent.end())
		inconsistent.insert(spy);
	else
		cost[spy] += (severity * get<0>(car[rent[spy]]) + 99)/100;
}

void solve()
{
	char spy[50];
	char e;
	scanf("%*d %s %c ", spy, &e);

	spyList.insert(spy);

	switch(e)
	{
		case 'p':
			pickup(spy);
			break;
		case 'r':
			returnCar(spy);
			break;
		case 'a':
			accident(spy);
	}
}

void init()
{
	car.clear();
	rent.clear();
	cost.clear();
	spyList.clear();
	inconsistent.clear();
}

int main() 
{
	int tc;
	scanf("%d\n", &tc);

	while(tc--)
	{
		init();

		int m, n;
		scanf("%d %d\n", &n, &m);

		int p, q, k;

		char name[50];
		while(n--)
			scanf("%s %d %d %d\n", name, &p, &q, &k), car[name] = make_tuple(p, q, k);

		while(m--)
			solve();

		for(auto &u : rent)
			inconsistent.insert(u.first);

		for(auto &u : spyList)
		{
			printf("%s ", u.c_str());
			if(inconsistent.find(u) == inconsistent.end())
				printf("%d", cost[u]);
			else
				printf("INCONSISTENT");
			printf("\n");
		}
	}

	return 0;
}
