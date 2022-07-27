#include <bits/stdc++.h>
using namespace std;

char in[3005];
char copy[3005];

char open[] = "[{<(";
char close[] = "]}>)";
char bracket[3005];

bool isOpenBracket(char c){return find(open, open+4, c) != open + 4;}
bool isClosedBracket(char c){return find(close, close+4, c) != close + 4;}
char matchBracket(char c){return open[find(close, close+4, c) - close];}

int main()
{
	while (fgets(in, 3005, stdin))
	{
		if(!strcmp(in, "\n"))
		{
			if(!fgets(in, 3005, stdin))
				return 0;
			printf("YES\n");
		}
		int top = -1;
		int count = 0;
		int balance = 0;
		for(int i = 0;in[i];++i)
		{
			++count;
			char c = in[i];
			if(!strncmp(in+i, "(*", 2))
				bracket[++top] = 'x', ++i, ++balance;
			else if(!strncmp(in+i, "*)", 2))
			{
				--balance;
				if(bracket[top] != 'x')
					break;
				else
					--top;
				++i;
			}
			else if(isOpenBracket(c)) bracket[++top] = c, ++balance;
			else if(isClosedBracket(c))
			{
				--balance;
				if(bracket[top] != matchBracket(c))
					break;
				else --top;
			}
		}
		if(top == -1 && !balance) printf("YES\n");
		else printf("NO %d\n", count);
	}
	return 0;
}