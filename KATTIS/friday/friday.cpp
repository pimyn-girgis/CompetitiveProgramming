#include <bits/stdc++.h>
using namespace std;


int main() 
{
	int t, m, d, cur, ans;
	scanf("%d", &t);
	while(t--)
	{
		cur = ans = 0;
		scanf("%d %d", &d, &m);
		while(m--)
		{
			scanf("%d", &d);
			if(!cur && d >= 13) ++ans;
			cur += d;
			cur %= 7;
		}
		printf("%d\n", ans);
	}
	return 0;
}
