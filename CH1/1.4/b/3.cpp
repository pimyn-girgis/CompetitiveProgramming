#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k;
	scanf("%d", &k);
	while(k--)
	{
	scanf("%d%d", &m, &n);
	m = m - 2; n = n - 2;
	while(m%3)
		++m;
	while(n%3)
		++n;
	printf("%d\n", m*n/9);
	}
	return 0;
}


