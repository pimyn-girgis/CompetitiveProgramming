#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, z = 0;
	scanf("%d%d", &x, &y);
	if(x != 0 && y == 1)
		printf("IMPOSSIBLE");
	else if(x == 0 && y == 1)
		printf("ALL GOOD");
	else
		printf("%f", x / (1.0 - y));
	return 0;
}

