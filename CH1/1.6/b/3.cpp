#include <bits/stdc++.h>
using namespace std;

int m, n, ans, r, c;

int main()
{
	while(scanf("%d%d", &r, &c))
	{
		if(!r && !c)
			return 0;

		m = max(r, c);
		n = min(r, c);

		if(n == 1)
			ans = m;
		else if(n == 2)
			ans = 2 * (m/2 + m%2 + !((m-2)%4));
		else
			ans = m*n/2 + m*n%2;
		printf("%d knights may be placed on a %d row %d column board.\n", ans, r, c);
	}
	return 0;
}

