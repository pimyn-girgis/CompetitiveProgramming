#include <bits/stdc++.h>
using namespace std;

int main()
{
	int g, s, c, x;
	scanf("%d%d%d", &g, &s, &c);
	x = 3 * g + 2 * s + c;
	if(x > 7)
		printf("Province or Gold");
	else if(x > 5)
		printf("Duchy or Gold");
	else if(x > 4)
		printf("Duchy or Silver");
	else if(x > 2)
		printf("Estate or Silver");
	else if(x > 1)
		printf("Estate or Copper");
	else
		printf("Copper");
	return 0;
}

