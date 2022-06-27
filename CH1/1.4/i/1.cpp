#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, x, l;
	scanf("%d", &n);
	vector<int> a (n);
	for(auto &u : a)
		scanf("%d", &u);
	scanf("%d", &m);
	vector<int> b (m);
	for(auto &u : b)
		scanf("%d", &u);
	m = 1e9;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d", &x);
			m = min(m, a[i] + b[x-1]);
		}
	}
	scanf("%d", &l);
	printf("%d", l/m? l/m-1 : 0);
	return 0;
}
