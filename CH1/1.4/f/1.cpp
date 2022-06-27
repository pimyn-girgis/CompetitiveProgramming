#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, x, y;
	while(scanf("%d%d%d%d", &a, &b, &c, &d))
	{
	if(!a)
		return 0;
	x = 10 * max(a, b) + min(a, b);
	y = 10 * max(c, d) + min(c, d);
	if(x == y)
		printf("Tie.");
	else if(x == 21)
		printf("Player 1 wins.");
	else if(y == 21)
		printf("Player 2 wins.");
	else if(x > y && !(x%11))
		printf("Player 1 wins.");
	else if(y > x && !(y%11))
		printf("Player 2 wins.");
	else if(!(x%11))
		printf("Player 1 wins.");
	else if(!(y%11))
		printf("Player 2 wins.");
	else if(x > y)
		printf("Player 1 wins.");
 	else if(y > x)
		printf("Player 2 wins.");
	printf("\n");
	}
	return 0;
}

