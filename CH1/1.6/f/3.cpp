#include <bits/stdc++.h>
using namespace std;

char scale[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}, input[1005];
bool key[12][12], there[12], ans[12];

void setKeys()
{
	memset(key, 0, sizeof(key));
	int move[7] = {0, 2, 2, 1, 2, 2, 2};
	for(int i = 0; i < 12; ++i)
		for(int j = 0, k = i; j < 7; ++j)
		{
			k += move[j];
			key[i][k%12] = 1;
		}
}
void check(char a, char b)
{
	for(int i = 0; i < 12; ++i)
		if(scale[i][0] == a)
		{
			there[i+ b == '#'] = 1;
			return;
		}
}
void solve(int k)
{
	for(int i = 0; i < 12; ++i)
		if(there[i] && !key[k][i])
			{
				ans[k] = 0;
				return;
			}
}

int main()
{
	setKeys();
	while(fgets(input, 1005, stdin) && strcmp(input, "END\n"))
	{
		bool first = 1;
		memset(there, 0, 12);
		memset(ans, 1, 12);
		for(int i = 0; input[i]; ++i)
		{
			if(isalpha(input[i]))
				check(input[i], input[i+1]);
		}
		for(int i = 0; i < 12; ++i)
			solve(i);
		for(int i = 0; i < 12; ++i)
			if(ans[i] && first) printf("%s", scale[i]), first = 0;
			else if(ans[i]) printf(" %s", scale[i]);
		printf("\n");
	}
	return 0;
}
