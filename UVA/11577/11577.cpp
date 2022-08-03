#include <bits/stdc++.h>
using namespace std;

char in[205];
int value[30];

int main()
{
	int tc;
	scanf("%d\n", &tc);
	while(tc--)
	{
		memset(value, 0, sizeof(value));

		fgets(in, 205, stdin);
		for(char *c = in;*c;++c)
			if(isalpha(*c))
				++value[tolower(*c) - 'a'];

		int maxVal = *max_element(value, value + sizeof(value)/sizeof(int));

		for(int i = 0; i < 26; ++i)
			if(maxVal == value[i])
				printf("%c", i + 'a');

		printf("\n");
	}
	return 0;
}
