#include <bits/stdc++.h>
using namespace std;

int nround, n, i, j;
int match(int &seed){return seed = seed % 2? seed / 2 + 1 : seed / 2;}
int main()
{
	while(scanf("%d%d%d", &n, &i, &j) != EOF)
	{
		nround = 1;
		while(match(i) != match(j))
			++nround;
		printf("%d\n", nround);
	}
	return 0;
}

