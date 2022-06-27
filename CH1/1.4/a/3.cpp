#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int m, n, l = 0;
	scanf("%llu", &m);

	while(m--)
	{
	      scanf("%llu", &n);
	      l = (sqrt(1+8*n) - 1)/2;
	      printf("%llu\n", l);
	}
	
	return 0;
}
