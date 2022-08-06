#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e5 + 5)

unordered_map <string , int> vote;
char *values[MAX];
char input[MAX];

bool compare(int x, int y, char* op)
{
	if(!strcmp(op, ">"))
		return x > y;
	else if(!strcmp(op, "<"))
		return x < y;
	else if(!strcmp(op, "<="))
		return x <= y;
	else if(!strcmp(op, ">="))
		return x >= y;
	else
		return x == y;
}

int main()
{
	int p, g;
	scanf("%d %d\n", &p, &g);

	char name[25];
	float num;

	while(p--)
		scanf("%s %f\n", name, &num), vote[name] = 10 * num;

	for(int guess = 1; guess <= g; ++guess)
	{
		fgets(input, MAX, stdin);

		int index = 0;
		for(char *token = strtok(input, " +\n");token; token = strtok(0, " +\n"))
			values[index++] = token;

		int sum = 0;
		for(int i = 0; i < index - 2; ++i)
			sum += vote[string(values[i])];

		char* comp = values[index - 2];
		int n = 10 * atoi(values[index - 1]);

		printf("Guess #%d was %s.\n", guess, compare(sum, n, comp) ? "correct" : "incorrect");
	}

	return 0;
}
