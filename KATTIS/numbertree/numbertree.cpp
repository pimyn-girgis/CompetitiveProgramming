//https://open.kattis.com/problems/numbertree
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	char input[40];
	fgets(input, 40, stdin);
	int height = atoi(strtok(input, " "));
	char *path = input + 1 + strlen(input);

	int ans = 1;

	for(char u = *path;u != '\n'; u = *(++path))
		ans = 2 * ans + (u == 'R');

	printf("%d\n", (1 << (height + 1)) - ans);

	return 0;
}
