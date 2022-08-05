#include <bits/stdc++.h>
using namespace std;

string first[1505];
string second[1505];
char in[15];

int main()
{
	int tc;
	scanf("%d", &tc);

	for(auto &u : second)
		u.resize(10);
	for(auto &u : first)
		u.resize(10);
	for(int test = 1; test <= tc; ++test)
	{
		set <string> language;

		int m, n;
		scanf("%d %d", &m, &n);
		while(getchar() != '\n');

		for(int i = 0; i < m; ++i)
			fgets(first[i].data(), 15, stdin);
		for(int i = 0; i < n; ++i)
			fgets(second[i].data(), 15, stdin);

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				language.insert(first[i] + second[j]);

		printf("Case %d: %lu\n", test, language.size());
	}
	return 0;
}
