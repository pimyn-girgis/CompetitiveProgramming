/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
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
	int tc;
	scanf("%d\n\n", &tc);

	while(tc--)
	{
		int n, h;
		scanf("%d %d", &n, &h);
		for(int i = 0; !(i & (1 << n)); ++i)
			if(__builtin_popcount(i ^ 0) == h)
			{
				for(int j = n - 1; j >= 0; --j)
					printf("%c", i & (1 << j)? '1' : '0');
				
				printf("\n");
			}
		
		if(tc) printf("\n");
	}

	return 0;
}
