#include <bits/stdc++.h>
using namespace std;

char in[135];
char brackets[135];
int top;

bool solve()
{
	fgets(in, 135, stdin);
	for(int i=0;in[i];++i)
	{
		char val = in[i];
		if(val == '(' || val == '[')
			brackets[++top] = val;
		else if(val == ']' && brackets[top] == '['
			 || val == ')' && brackets[top] == '(')
			 {
				if(top < 0) return 0;
				else --top;
			 }
		else if(in[i] != '\n')
			return 0;
	}
	return top == -1;
}
int main()
{
	int n;
	fgets(in, 135, stdin);
	n = atoi(in);
	while(n--)
	{
		top = -1;
		printf(solve()? "Yes\n" : "No\n");
	}
	return 0;
}
