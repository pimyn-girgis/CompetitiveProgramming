#include <bits/stdc++.h>
using namespace std;

int main()
{
	char c [31];
	bool x = 0;
	scanf("%s", c);
	for(int i = 0; c[i] != '\0'; ++i)
		if(c[i] == 's' && c[i+1] == 's')
			x = 1;
	if(x)
		printf("hiss");
	else
		printf("no hiss");
	return 0;
}

