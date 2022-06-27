#include <bits/stdc++.h>
using namespace std;

int main()
{
int t, n, k, p, c = 0;
scanf("%d", &t);
while(t--)
	{
	scanf("%d%d%d", &n, &k, &p);
	p += k;
	p %= n;
	if(p == 0) p = n;
	printf("Case %d: %d\n",++c, p);
	}
return 0;
}
