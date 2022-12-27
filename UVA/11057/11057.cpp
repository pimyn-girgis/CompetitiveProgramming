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

int arr[10005];

int main()
{
	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		
		sort(arr, arr + n);
		scanf("%d", &m);

		int first = 0, second = n - 1;

		for(int i = 0, j = n - 1; i < j;)
		{
			int sum = arr[i] + arr[j];
			if(sum == m) first = i++, second = j--;
			else if(sum < m) ++i;
			else --j;
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", arr[first], arr[second]);
	}

	return 0;
}
