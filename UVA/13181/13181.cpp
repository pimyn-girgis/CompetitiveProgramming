#include <bits/stdc++.h>
using namespace std;

char line[500005];
int val, n, len;
char *token;

#define calc(n) (n-1)>>1

void first()
{
	val = 0;
	token = strtok(line, "X");
	n = strlen(token);
	if(line[0] == '.') val = n-1;
	else val = calc(n);
}

void solve()
{
	first();
	while(token)
	{
		n = strlen(token);
		val = max(val, calc(n));
		token = strtok(0, "X");
		if(!token && line[len-1] == '.') val = max(val, n-1); //handles last
	}
}

int main()
{
	while(scanf("%s%n", line, &len) != EOF)
	{
		solve();
		printf("%d\n", val);
	}
	return 0;
}