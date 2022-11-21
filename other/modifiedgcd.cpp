/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* problem : modified gcd
**************************************************************
*/
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, n;
	scanf("%d %d %d\n", &a, &b, &n);

	set<int> divisors;
	if(a < b) swap(a, b);

	for(int i = 1; i <= b / i; ++i)
	{
		if(!(a % i || b % i))
			divisors.insert(i);

		int j = b / i;

		if(!(a % j || b % j))
			divisors.insert(j);
	}

	while(n--)
	{
		int low, high;
		scanf("%d %d", &low, &high);

		auto it = divisors.upper_bound(high);
		printf("%d\n", it != divisors.begin() && *(--it) >= low? *it : -1);
	}

	return 0;
}

