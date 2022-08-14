//https://open.kattis.com/problems/compoundwords
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	char input[15];
	vector <string> wordList;
	wordList.reserve(105);
	set <string> compoundWordList;

	while(scanf("%s", input) != EOF)
		wordList.push_back(input);

	for(auto i = wordList.begin(); i != wordList.end(); ++i)
		for(auto j = wordList.begin(); j != wordList.end(); ++j)
			if(i != j) compoundWordList.insert(*i + *j);

	for(auto &u : compoundWordList)
		printf("%s\n", u.c_str());

	return 0;
}
