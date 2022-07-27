#include <bits/stdc++.h>
using namespace std;

char low[3] = "+-";
char high[3] = "*/";

bool isHigh(char c){return find(high, high+2, c) != high + 2;}
bool isLow(char c){return find(low, low+2, c) != low + 2;}
bool higher_or_equal(char c, char d){return isHigh(c) || isLow(d);}

int main()
{
	char in[5], val, stack[60];
	int tc, top;

	scanf("%d\n\n", &tc);
	while(tc--)
	{
		top = -1;
		while(1)
		{
			if(!fgets(in, 5, stdin)) break;
			val = in[0];
			if(val == '\n')
				break;
			
			if(isdigit(val))
				printf("%c", val);
			else
			{
				if(val == '(')
					stack[++top] = val;
				else if(val == ')')
					while(top >= 0 && stack[top--] != '(')
						printf("%c", stack[top+1]);
				else
				{
					while(top >= 0 && higher_or_equal(stack[top], val) && stack[top] != '(')
						printf("%c", stack[top--]);
					stack[++top] = val;
				}
			}
		}
		while(top >= 0)
			printf("%c", stack[top--]);
		printf("\n");
		if(tc) printf("\n");
	}
	return 0;
}