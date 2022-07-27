//https://open.kattis.com/problems/delimitersoup
#include <bits/stdc++.h>
using namespace std;

char program[205];
char str[205];
char bracket;
int top = -1;

int main() 
{
	int l;
	scanf("%d ", &l);
	fgets(str, 205, stdin);
	for(int i=0;str[i];++i)
	{
		bracket = str[i];

		if(isspace(bracket))
			continue;

		if(bracket == '[' || bracket == '{' || bracket == '(')
			program[++top] = bracket;
		else
		{
			char match = program[top--];
			if(bracket == ']' && match != '['
			|| bracket == '}' && match != '{'
			|| bracket == ')' && match != '(')
			{
				printf("%c %d\n", bracket, i);
				return 0;
			}
		}
	}
	printf("ok so far\n");
	return 0;
}
