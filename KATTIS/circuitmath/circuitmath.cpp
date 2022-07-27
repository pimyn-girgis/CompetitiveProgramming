//https://open.kattis.com/problems/circuitmath
#include <bits/stdc++.h>
using namespace std;

char in[1005];
bool on[30];
bool eval[1000];
int top = -1;

int main() 
{
	int n;
	scanf("%d ", &n);
	fgets(in, 1000, stdin);
	
	for(int i = 0, ind = 0;in[i];++i)
	{
		char val = in[i];
		if(isspace(val))
			continue;
		if(val == 'T')
			on[ind++] = 1;
		else if(val == 'F')
			on[ind++] = 0;
	}

	fgets(in, 1000, stdin);
	for(int i = 0;in[i];++i)
	{
		char val = in[i];

		if(isspace(val))
			continue;
		
		if(val == '*')
		{
			eval[top-1] = eval[top] * eval[top-1];
			--top;
		}
		else if(val == '+')
		{
			eval[top-1] = eval[top] + eval[top-1];
			--top;
		}
		else if(val == '-')
		{
			eval[top] = !eval[top];
		}
		else
		{
			eval[++top] = on[val - 'A'];
		}
	}
	printf(*eval? "T\n" : "F\n");
	return 0;
}
