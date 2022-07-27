#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e8)

char in[MAX];
int doll[MAX];
int sum[MAX];

int main()
{
	while(fgets(in, MAX, stdin))
	{
		int top = -1;
		bool correct = 1;
		for(char *token = strtok(in, " \n");token && correct;token = strtok(0, " \n"))
		{
			int val = atoi(token);
			if(val < 0)
			{
				doll[++top] = val;
				sum[top] = 0;
				if(top > 0 && (sum[top-1] += doll[top]) <= doll[top-1])
					correct = 0;
			}
			else if(top < 0 || val != -doll[top])
					correct = 0;
			else --top;
		}
		printf(correct && top == -1? ":-) Matrioshka!\n" : ":-( Try again.\n");
	}
	return 0;
}