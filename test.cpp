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
				if(word[i] == word[i+1] && (find(vowel, vowel + 6, word[i]) != vowel + 6))
					++val;

			if(val > ans.second)
				ans = make_pair(word, val);
		}

		printf("%s\n", ans.first.c_str());
	}
	
	return 0;
}