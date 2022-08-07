//https://open.kattis.com/problems/conversationlog
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef pair <int, string> pis;
#define MAX int(1e7)
char in[MAX];


int main() 
{
	int m;
	scanf("%d\n", &m);

	unordered_map <string, int> freq;
	unordered_map<string, unordered_set<string> > used; //word, list of users
	unordered_set <string> names;

	for(int i = 0; i < m; ++i)
	{
		fgets(in, MAX, stdin);

		string name= strtok(in, " \n");
		names.insert(name);

		for(char *token = strtok(0, " \n"); token; token = strtok(0, " \n"))
			++freq[string(token)], used[token].insert(name);
	}

	vector <pis> out;
	for(auto &u : freq)
		if(used[u.first].size() == names.size())
			out.push_back(make_pair(u.second, u.first));

	if(out.empty())
		printf("ALL CLEAR\n");
	else
	{
		sort(out.begin(), out.end(),
			[](pis x, pis y)
			{
				if(x.first != y.first)
					return x.first > y.first;
				return x.second < y.second;
			});

		for(auto &u : out) 
			printf("%s\n", u.second.c_str());
	}

	return 0;
}
