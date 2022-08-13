#include <bits/stdc++.h>
using namespace std;

char input[205];
char sep[128];

int main()
{

	iota(sep, sep + 127, 1);
	sep[127] = 0;
	for(auto &u : sep)
		if(isalpha(u))
			u = 1;

	set <string> dictionary;

	while(fgets(input, sizeof(input), stdin))
	{
		for(char *c = input; *c; ++c)
			*c = tolower(*c);

		for(char *token = strtok(input, sep); token; token = strtok(0, sep))
			dictionary.insert(token);
	}

	for(auto &u : dictionary)
		printf("%s\n", u.c_str());

	return 0;
}
