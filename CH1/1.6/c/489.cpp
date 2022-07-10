//Hangman Judge UVA 00489
#include <bits/stdc++.h>
using namespace std;

int roundNum, stroke, val, cmp, total, trials;
char ans[100], input[100];
bool chr[26], yes, win, lose;
int main()
{
	while(scanf("%d", &roundNum) && roundNum != -1)
	{
		memset(chr, 0, 26);
		scanf("%s%s", ans, input);
		stroke = total =  win = lose = trials = 0;
		printf("Round %d\n", roundNum);
		for(int i = 0; ans[i]; ++i)
			for(int j = i + 1; ans[j]; ++j)
				if(ans[i] == ans[j])
					ans[j] = 'S';
		for(int i = 0; ans[i]; ++i)
			if(ans[i] != 'S')
				++total;
		for(int i = 0; input[i] && !win && !lose; ++i)
		{
			val = input[i] - 'a';
			yes = 0;
			for(int j = 0; ans[j]; ++j)
			{
				if(input[i] == ans[j] && !chr[val])
					{
						yes = 1;
						++trials;
					}
			}
			if(!yes && !chr[val])
				++stroke;
			chr[val] = true;

			if(stroke >= 7 && !win && !lose)
			{
				printf("You lose.\n");
				lose = 1;
			}
			else if(trials == total && !win && !lose)
			{
				printf("You win.\n");
				win = 1;
			}
		}
		if(!win && !lose)
			printf("You chickened out.\n");
	}
	return 0;
}