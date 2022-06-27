#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y;
	while(scanf("%d%d", &x, &y))
	{
		if(x == 0 && y == 0)
			return 0;
		if(x + y == 13)
			printf("Never speak again.");
		else if(x == y)
			printf("Undecided.");
		else if(x > y)
			printf("To the convention.");
		else
			printf("Left beehind.");
		printf("\n");
	}

	return 0;
}

