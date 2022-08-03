#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e6)

char in[MAX];
int freq[128];

int main()
{
	while (fgets(in, MAX, stdin))
	{
		memset(freq, 0, sizeof(freq));

		for(char *c = in; *c; ++c)
			freq[*c] += bool(isalpha(*c)); //isalpha(int c) does not return a boolean value but an integer value.

		int maxVal = *max_element(freq, freq + 127);

		if(maxVal)
		{
			for(int i = 0; i < 128; ++i)
				if(freq[i] == maxVal)
					printf("%c", i);

			printf(" %d\n", maxVal);
		}
	}
	return 0;
}
