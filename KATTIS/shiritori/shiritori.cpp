//https://open.kattis.com/problems/shiritori
#include <bits/stdc++.h>
using namespace std;

char word[130];
set <string> already_said;

int main() 
{
	int n;
	scanf("%d", &n);

	int len, lose;
	char prev = 0;
	bool fair = 1;

	for(int i = 0; i < n; ++i)
	{
		scanf("%s%n", word, &len);
		if(fair)
		{
			if(already_said.find(word) != already_said.end())
				fair = 0, lose = i % 2 + 1;
			else
			{
				already_said.insert(word);

				if(prev == *word || !prev)
					prev = word[len - 2];
				else fair = 0, lose = i % 2 + 1;
			}
		}
	}

	printf(fair? "Fair Game\n" : "Player %d lost\n", lose);

	return 0;
}
