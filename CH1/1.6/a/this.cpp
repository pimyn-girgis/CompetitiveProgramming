#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, speed, prev, sum;
	while (scanf("%d", &n), n != -1)
	{
		prev = sum = 0;
		while(n--)
		{
			scanf("%d%d", &speed, &t);
			sum += speed * (t - prev);
			prev = t;
		}
		printf("%d miles\n", sum);
	}
}