//https://open.kattis.com/problems/joinstrings
#include <bits/stdc++.h>
using namespace std;

char in[int(1e6 + 5)];

int main()
{
	int n;
	scanf("%d", &n);

	list <char> str[n];

	for(int i = 0;i < n;++i)
	{
		scanf("%s%n", in);
		for(int j = 0;in[j];++j)
			str[i].push_back(in[j]);
	}

	int a, b;

	for(int i = 1;i < n;++i)
	{
		scanf("%d %d", &a, &b);
		--a; --b;
		str[a].splice(str[a].end(), str[b]);
	}

	for(auto &u : str[a])
		printf("%c", u);

	printf("\n");
	return 0;
}