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

vector<long long> sol;

void preprocess()
{
	long long two = 1;
	for(int i = 0; i < 32; ++i)
	{
		long long three = 1;
		for(int j = 0; j < 32; ++j)
		{
			sol.push_back(two * three);
			three *= 3;
		}

		two *= 2;
	}

	sort(sol.begin(), sol.end());
}

int main()
{
	preprocess();

	long long m;
	while(scanf("%lld", &m), m)
		printf("%lld\n", *lower_bound(sol.begin(), sol.end(), m));
	
	return 0;
}
