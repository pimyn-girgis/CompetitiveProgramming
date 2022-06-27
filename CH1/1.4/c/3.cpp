#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if(x == 0 && y == 0)
		printf("Not a moose");
	else if(x == y)
		printf("Even %d", 2 * x);
	else
		printf("Odd %d", 2 * max(x, y));
	return 0;
}

