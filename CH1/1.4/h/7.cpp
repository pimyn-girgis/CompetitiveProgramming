#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char, int> m;
	char c [3];
	int x = 0;
	for(int i = 0; i < 5;++i)
	{
		scanf("%s", c);
		m.insert(pair<char, int>(c[0], 0));
		++m[c[0]];
	}
	for(auto u : m)
		x = max(x, u.second);
	printf("%d", x);
	return 0;
}

