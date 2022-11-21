/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 11991 UVA
* Link    : https://onlinejudge.org/external/119/p11991.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

const int len = 1e5 + 5;

int main()
{
	unordered_map<int, vector<int>> arr;
	arr.reserve(2 * len);

	int m, n;
	while(scanf("%d %d\n", &n, &m) != EOF)
	{
		int val;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &val);
			arr[val].push_back(i);
		}

		int k, v;
		while(m--)
		{
			scanf("%d %d\n", &k, &v);
			printf("%d\n", arr[v].size() >= k? arr[v][k - 1] : 0);
		}
	}
	
	return 0;
}
