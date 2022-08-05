#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() 
{
	int jack, jill;
	while(scanf("%d %d", &jack, &jill), jack || jill)
	{
		unordered_set <int> cd;

		int total = jack + jill;

		int val;
		int ans = 0;
		while(total--)
		{
			scanf("%d", &val);
			if(cd.find(val) != cd.end()) ++ans;
			else cd.insert(val);
		}

		printf("%d\n", ans);
	}
	return 0;
}
