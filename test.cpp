#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	vector <tuple<long double, int, int> > v(n);

	for(int i = 0; i < n; ++i)
	{
		auto &[weight_for_cost, cost, weight] = v[i];
		scanf("%d %d", &weight, &cost);
		weight_for_cost = float(weight)/cost;
	}

	int sum = 0;
	sort(v.begin(), v.end());

	auto it = v.begin();
	int totalCost = 0;
	while(sum < s && it != v.end())
	{
		auto &[weight_for_cost, cost, weight] = *it;
		if(weight + sum < s)
			sum += weight, totalCost += cost;
		else
			++it;
	}

	printf("%d\n", totalCost);

	return 0;
}