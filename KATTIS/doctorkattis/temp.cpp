//https://open.kattis.com/problems/doctorkattis
#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> level;
map <int, map<int, string>, greater<int> > query;

int erase(int old, char *name)
{
	int ans = 0;
	if(query[old].size() <= 1)
		query.erase(old);

	else
		for(auto it = query[old].begin(); it != query[old].end(); ++it)
			if(!strcmp(it->second.c_str(), name))
			{
				ans = it->first;
				query[old].erase(it);
				break;
			}

	return ans;
}

int main() 
{
	int n;
	scanf("%d", &n);
	
	int ind = 0;
	while(n--)
	{
		int cmd;
		scanf("%d", &cmd);

		char name[20];
		int infection;

		if(!cmd)
		{
			scanf("%s %d", name, &infection);
			level[name] = infection;
			query[infection].insert(make_pair(++ind, name));
		}
		else if(cmd == 1)
		{
			scanf("%s %d", name, &infection);

			int old = level[name];
			level[name] += infection;
			query[level[name]].insert(make_pair(erase(old, name), name));
		}
		else if(cmd == 2)
		{
			scanf("%s", name);

			erase(level[name], name);
			level.erase(name);
		}
		else if(cmd == 3)
			printf("%s\n", query.empty()? "The clinic is empty" : query.begin()->second.begin()->second.c_str());
	}
	return 0;
}


