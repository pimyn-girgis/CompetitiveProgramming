#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		multiset <int> bills;

		long long unsigned int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			int billsInDay;
			scanf("%d", &billsInDay);

			int val;
			while(billsInDay--)
				scanf("%d", &val), bills.insert(val);

			sum += *bills.rbegin() - *bills.begin();

			bills.erase(bills.begin());
			bills.erase(--bills.rbegin().base());
		}

		printf("%llu\n", sum);
	}
	
	return 0;
}
