#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	int ans = 0;
	if(n < 10)
		return n;
	while(n)
	{
		ans += n%10;
		n /= 10;
	}
	n = solve(ans);
	return n;
}
int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(!n)
			return 0;
		printf("%d\n", solve(n));
	}
	return 0;
}

