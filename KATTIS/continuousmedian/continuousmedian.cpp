/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : continuousmedian Kattis
* Link    : https://open.kattis.com/problems/continuousmedian
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		ost arr;
		int n;
		scanf("%d", &n);

		long long unsigned sum = 0;

		for(int i = 1; i <= n; ++i)
		{
			int val;
			scanf("%d", &val);
			arr.insert(val);

			auto it = arr.find_by_order(arr.size() / 2);

			sum += arr.size() & 1? *it : (*it + *--it) / 2;
		}

		printf("%llu\n", sum);
	}

	return 0;
}
