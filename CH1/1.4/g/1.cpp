#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, i = 1;
	scanf("%d", &n);
	vector <int> v(n, 1);
	while(--n)
	{
		scanf("%d", &x);
		v[x+1] = ++i;
	}
	for(auto u: v)
		printf("%d ", u);
	return 0;
}

