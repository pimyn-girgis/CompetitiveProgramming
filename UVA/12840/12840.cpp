/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12840 UVA
* Link    : https://onlinejudge.org/external/128/p12840.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int arr[55];
vector<int> ans;

int solve(int len, int sum)
{
	long long taken = 0;

	for(int i = 0; i < len; ++i)
	{
	}
}

int main()
{
	int tc;
	scanf("%d\n", &tc);
	
	for(int caseNo = 1; caseNo <= tc; ++caseNo)
	{
		int n, s;
		scanf("%d %d\n", &n, &s);

		for(int i = 0; i < n; ++k)
			scanf("%d%*c", arr + i);
		
		solve();

		printf("Case %d: [%zu]", caseNo, ans.size());
		for(auto u : ans) printf(" %d", u);
		printf("\n");
	}
	
	
	return 0;
}
