/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10576 UVA
* Link    : https://onlinejudge.org/external/105/p10576.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int year[12];

bool test()
{
	int sum = 0;
	for(int i = 0; i < 12; ++i)
	{
		sum += year[i];
		if(i >= 4)
		{
			if(sum >= 0)
				return false;

			sum -= year[i - 4];
		}
	}

	return true;
}

bool solve(int s, int d, int len = 12)
{
	if(!len) return test() && accumulate(year, year + 12, 0) >= 0;

	year[len - 1] = s;
		if(solve(s, d, len - 1)) return true;
	year[len - 1] = -d;
		if(solve(s, d, len - 1)) return true;

	return false;
}

int main()
{
	int s, d;

	while(scanf("%d %d\n", &s, &d) != EOF)
	{
		memset(year, -1, sizeof(year));
		if(solve(s, d)) printf("%d\n", accumulate(year, year + 12, 0));
		else printf("Deficit\n");
	}
	
	return 0;
}
