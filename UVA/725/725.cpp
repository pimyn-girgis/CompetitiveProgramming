/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 00725 UVA
* Link    : https://onlinejudge.org/external/7/p725.pdf
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
	bool first = 1;
	while(scanf("%d", &n), n)
	{
		bool flag = 1;
		if(!first)
			printf("\n");
		else first = 0;

		for(int low = 1234; low <= 98765 / n; ++low)
		{
			int high = low * n;
			int temp, used = (low < 10000);
			temp = high; while(temp){used |= 1 << (temp % 10); temp /= 10;}
			temp = low; while(temp){used |= 1 << (temp % 10); temp /= 10;}
			if(used == (1 << 10) - 1)
			{
				printf("%05d / %05d = %d\n", high, low, n);
				flag = 0;
			}
		}

		if(flag)
			printf("There are no solutions for %d.\n", n);
	}

	return 0;
}
