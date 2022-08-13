#include <bits/stdc++.h>
using namespace std;

typedef multiset<int, greater<int> > mi;

void out(mi &winner, string name)
{
	printf("%s wins\n", name.c_str());

	for(auto &u : winner)
		printf("%d\n", u);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		mi blue;
		mi green;
		int f, g, b;
		scanf("%d %d %d", &f, &g, &b);

		vector <pair<bool, int> > field(f); //blue = 1, green = 0

		int val;
		for(int i = 0; i < g; ++i) scanf("%d", &val), green.insert(val);
		for(int i = 0; i < b; ++i) scanf("%d", &val), blue.insert(val);

		while(green.size() && blue.size())
		{
			field.resize(min(f, int(min(green.size(), blue.size()))));
			auto it = field.begin();

			for(int i = 0; i < field.size(); ++i, ++it)
			{
				auto b = blue.begin();
				auto g = green.begin();

				it->first = *b > *g;
				it->second = abs(*b - *g);

				blue.erase(b);
				green.erase(g);
			}

			for(auto &u : field)
				if(u.first && u.second)
					blue.insert(u.second);
				else if(u.second)
					green.insert(u.second);
		}

		if(blue.size()) out(blue, "blue");
		else if(green.size()) out(green, "green");
		else printf("green and blue died\n");

		if(tc) printf("\n");
	}

	return 0;
}

/*
10 10 
10 10 10
*/