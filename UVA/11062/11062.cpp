/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

char sep[128];
char input[500];

void preprocess()
{
	iota(sep, sep + 127, 1);

	for(auto &u : sep)
		if(isalpha(u) || u == '-')
			u = 1;
}

int main()
{
	preprocess();

	set <string> dictionary;

	string cur;
	while(scanf("%s", input) != EOF)
	{
		for(char *token = strtok(input, sep); token; token = strtok(0, sep))
		{
			int len = 0;
			for(char *c = token; *c; ++c)
				*c = tolower(*c), ++len;

			if(token[len - 1] != '-')
			{
				dictionary.insert(cur + token);
				cur.clear();
				continue;
			}
			
			token[len - 1] = 0;
			cur += token;
		}
	}

	for(auto &u : dictionary)
		printf("%s\n", u.c_str());

	return 0;
}