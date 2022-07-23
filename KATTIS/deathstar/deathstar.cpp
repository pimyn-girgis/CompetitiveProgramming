//https://open.kattis.com/problems/deathstar
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, in;
	scanf("%d", &n);
	for(int i = 0, val;i < n;++i)
	{	
		val = 0;
		for(int j=0;j<n;++j)
			scanf("%d", &in), val |= in;
		printf("%d%c", val, i == n-1? '\n' : ' ');
	}
	return 0;
}
