//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

char key[] = " \n";
char input[1000];
int main() 
{
	unordered_map<string, int> dictionary;
	unordered_map<int, string> value;

	while(fgets(input, sizeof(input), stdin))
	{
		vector <char*> text;

		char *cmd = strtok(input, key);
		while(char *token = strtok(0, key))
			text.push_back(token);

		if(!strcmp(cmd, "def"))
		{
			if(dictionary.find(text[0]) != dictionary.end())
				value.erase(dictionary[text[0]]);
			dictionary[text[0]] = atoi(text[1]);
			value[dictionary[text[0]]] = text[0];
		}
		else if(!strcmp(cmd, "clear"))
			dictionary.clear(), value.clear();
		else if(!strcmp(cmd, "calc"))
		{
			bool pass = 1;
			int sum = 0;
			int sign = 1;
			for(auto &u : text)
			{
				if(!strcmp(u, "-")) sign = -1;
				else if(!strcmp(u, "+")) sign = 1;
				else if(strcmp(u, "="))
				{
					if(dictionary.find(u) == dictionary.end())
					{
						pass = 0;
						break;
					}
					sum += sign * dictionary[u];
				}
			}

			pass &= (value.find(sum) != value.end());

			for(auto &u : text) printf("%s ", u);
			printf("%s\n", pass?  value[sum].c_str() : "unknown");
		}
	}
	return 0;
}