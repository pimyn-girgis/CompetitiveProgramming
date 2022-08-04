//https://open.kattis.com/problems/quickbrownfox
#include <bits/stdc++.h>
using namespace std;

char phrase[105];

int main() 
{
	int n;
	scanf("%d\n", &n);

	bitset<26> pangram;

	while(n--)
	{
		pangram.reset();

		fgets(phrase, 104, stdin);
		
		for(char *c = phrase;*c;++c)
			if(isalpha(*c))
				pangram.set(tolower(*c) - 'a');

		if(pangram.all()) printf("pangram\n");
		else
		{
			printf("missing ");

			for(int i = 0; i < 26; ++i)
				if(!pangram.test(i))
					printf("%c", i + 'a');

			printf("\n");
		}
	}
	return 0;
}
