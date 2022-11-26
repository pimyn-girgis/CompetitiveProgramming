/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10684 UVA
* Link    : https://onlinejudge.org/external/106/p10684.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
	int n;
	
	while(scanf("%d", &n), n)
	{
		int val = 0;
		int sum = 0;
		int max_sum = 0;

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &val);
			max_sum = max(sum += val, max_sum);
			if(sum < 0) sum = 0;
		}

		if(max_sum) printf("The maximum winning streak is %d.\n", max_sum);
		else printf("Losing streak.\n");
	}

	return 0;
}
