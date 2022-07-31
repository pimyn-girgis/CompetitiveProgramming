#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int> 

int main()
{
	unordered_map <int, int> period;
	priority_queue <ii, vector<ii >, std::greater<ii > > pq;

	char in[15];

	while(scanf("%s", in), in[0] != '#')
	{
		int query, val;
		scanf("%d %d", &query, &val);
		period[query] = val;

		pq.push(ii(val, query));
	}
	
	int k;
	scanf("%d", &k);

	while(k--)
	{
		auto val = pq.top(); pq.pop();
		printf("%d\n", val.second);
		val.first += period[val.second];
		pq.push(val);
	}

	return 0;
}
