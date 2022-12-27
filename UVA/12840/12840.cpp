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


int n;
int arr[55];

vector<int> ans;
vector<int> shelf;

void rec(int i, int target) {
	if (!target) {
		if (ans.empty() || shelf.size() < ans.size())
		ans = shelf;
		return;
	}
	if (target < 0) return;
	if (!ans.empty() && ans.size() <= shelf.size()) return;
	if (i >= n) return;

	const int x = arr[i];
	for (int j = target / x; j > 0; j--) {
		shelf.push_back(x);
	}
	for (int j = target / x; j > 0; j--) {
		rec(i+1, target - j * arr[i]);
		shelf.pop_back();
	}
	rec(i+1, target);
}

int main()
{
	int tc, s;
	scanf("%d\n", &tc);
	
	for(int caseNo = 1; caseNo <= tc; ++caseNo)
	{
        ans.clear();
        shelf.clear();
		scanf("%d %d\n", &n, &s);

		for(int i = 0; i < n; ++i)
			scanf("%d%*c", arr + i);
		
		reverse(arr, arr + n);

		printf("Case %d: ", caseNo);

		rec(0, s);
		
		if(!ans.empty())
		{
			printf("[%zu]", ans.size());
			for(auto u : ans)
				printf(" %d", u);
		}
		else printf("impossible");

		printf("\n");
	}
	
	return 0;
}
