#include <bits/stdc++.h>
using namespace std;

void tokenize(map<string, string> &dic)
{
	char in[105];
	char key[] = "{},:\n";
	scanf("%s", in);

	char *word;
	for(char *token = strtok(in, key), *word; token; token = strtok(0, key))
		if(isdigit(*token))
			dic[word] = token;
		else word = token;
}

void out(set<string> &s, char sign)
{
	printf("%c", sign);
	for(auto it = s.begin(); it != s.end(); ++it)
		printf("%s%c", it->c_str(), it == --s.end()? '\n' : ',');
}

int main()
{
	int tc;
	scanf("%d\n", &tc);
	while(tc--)
	{
		map <string, string> oldDictionary;
		map <string, string> newDictionary;

		tokenize(oldDictionary);
		tokenize(newDictionary);

		set <string> added;
		set <string> removed;
		set <string> edited;

		for(auto &u : newDictionary)
			if(oldDictionary.find(u.first) == oldDictionary.end())
				added.insert(u.first);
			else if(oldDictionary[u.first] != newDictionary[u.first])
				edited.insert(u.first);

		for(auto &u : oldDictionary)
			if(newDictionary.find(u.first) == newDictionary.end())
				removed.insert(u.first);

		if(added.empty() && removed.empty() && edited.empty()) printf("No changes\n");
		if(!added.empty()) out(added, '+');
		if(!removed.empty()) out(removed, '-');
		if(!edited.empty()) out(edited, '*');

		printf("\n");
	}
	return 0;
}
