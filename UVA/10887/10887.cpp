#include <bits/stdc++.h>
using namespace std;

string first[1505];
string second[1505];
char in[15];

int main()
{
	cin.tie(NULL);
	int tc;
	cin >> tc;

	for(int test = 1; test <= tc; ++test)
	{
		unordered_set <string> language;

		int m, n;
		cin >> m >> n;
		cin.ignore();

		for(int i = 0; i < m; ++i)
			getline(cin, first[i], '\n');
		for(int i = 0; i < n; ++i)
			getline(cin, second[i], '\n');

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				language.insert(first[i] + second[j]);

		printf("Case %d: %lu\n", test, language.size());
	}
	return 0;
}
