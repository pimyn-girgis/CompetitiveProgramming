//https://open.kattis.com/problems/awkwardparty
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);

	unordered_map <int, set<int> > lang;
	lang.reserve(2 * n);

	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);

		lang[val].insert(i);
	}

	int ans = n;
	for(auto &u : lang)
	{
		auto &v = u.second;
		int prev = -1;

		for(auto it = v.begin(); it != v.end(); ++it)
		{
			if(prev != -1)
				ans = min(ans, *it - prev);
			prev = *it;
		}
	}

	printf("%d\n", ans);

	return 0;
}
