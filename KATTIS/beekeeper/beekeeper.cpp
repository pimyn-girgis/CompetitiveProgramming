//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
using namespace std;

char vowel[] = "aeiouy";

int main()
{
	int tc;
	while(scanf("%d", &tc), tc)
	{
		pair<string, int> ans("", -1);

		char word[100];
		while(tc--)
		{
			int val = 0;
			scanf("%s", word);

			for(int i = 0; word[i+1]; ++i)
				if(word[i] == word[i+1] && (find(vowel, vowel + sizeof(vowel), word[i]) != vowel + sizeof(vowel)))
					++val;

			if(val > ans.second)
				ans = make_pair(word, val);
		}

		printf("%s\n", ans.first.c_str(), ans.second);
	}
	
	return 0;
}