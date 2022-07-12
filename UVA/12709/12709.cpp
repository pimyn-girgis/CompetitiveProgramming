#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, w, h, t, g=10;
	while(scanf("%d", &t) && t)
	{
		int ans = 0;
		float val = 0, maxAcc = 0;
		while(t--)
		{
			scanf("%d %d %d", &l, &w, &h);
			val = g - float(g)/(2*h);
			if(maxAcc <= val)
			{
				if(maxAcc == val)
					ans = max(ans, l*w*h);
				else
				{
					ans = l*w*h;
					maxAcc = val;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
