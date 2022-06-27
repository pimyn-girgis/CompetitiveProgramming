#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts, s, d, big, small;
	scanf("%d", &ts);
	while(ts--)
	{
		bool possible = 1;
		scanf("%d %d", &s, &d);
		big = (d + s) / 2;
		small = (s - d) / 2;
		if(big >= small
		&& small >= 0
		&& big + small == s
		&& big - small == d)
			printf("%d %d\n", big, small);
		else
			printf("impossible\n");
	}
	return 0;
}