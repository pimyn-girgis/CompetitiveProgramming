//https://open.kattis.com/problems/doctorkattis
#include <bits/stdc++.h>
using namespace std;

struct cat
{
	string name;
	int level;
	int index;

	bool operator <(const cat &y) const
	{
		if(level != y.level)
			return level > y.level;
		
		return index < y.index;
	}

	cat(char *x, int y, int z)
		: level (y), name (x), index (z){};
};

int main()
{
	set <cat> query;
	unordered_map <string, pair<int, int> > infection; //infection level / index

	int n;
	int index = 0;
	scanf("%d", &n);

	while(n--)
	{
		char name[20];
		int level;

		int cmd;
		scanf("%d", &cmd);

		switch (cmd)
		{
			case 0:
			{
				scanf("%s %d", name, &level);

				query.insert(cat(name, level, ++index));
				infection[name] = make_pair(level, index);
				break;
			}
			case 1:
			{
				scanf("%s %d", name, &level);

				auto &temp = infection[name];
				query.erase(cat(name, temp.first, temp.second));

				temp.first += level;
				query.insert(cat(name, temp.first, temp.second));
				break;
			}
			case 2:
			{
				scanf("%s", name);

				auto &temp = infection[name];
				query.erase(cat(name, temp.first, temp.second));

				infection.erase(name);
				break;
			}
			case 3:
			{
				printf("%s\n", query.empty()? "The clinic is empty" : query.begin()->name.c_str());
			}
		}
	}

	return 0;
}