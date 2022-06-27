#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool inc = 0;
	bool dec = 0;
	int t;
	scanf("%d", &t);
	char c[t][13];
	for(int i = 0; i < t; ++i)
		scanf("%s", c[i]);
	for(int i = 0; i < t - 1; ++i)
		if(strcmp(c[i], c[i+1]) < 0)
			inc = 1;
		else if(strcmp(c[i], c[i+1]))
			dec = 1;
	if(inc && dec)
		printf("NEITHER");
	else if(inc)
		printf("INCREASING");
	else
		printf("DECREASING");
	return 0;
}

