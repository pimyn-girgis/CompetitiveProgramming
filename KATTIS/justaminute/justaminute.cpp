#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, m, s, min=0, sec=0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d", &m, &s);
		min += 60 * m, sec += s;
	}
	float ans = float(sec)/min;
	if (ans > 1) printf("%.7f\n", ans);
	else printf("measurement error\n");
	return 0;
}
