#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[3], m;
	for(auto &u : a)
		scanf("%d", &u);
	sort(a, a+3);
	m = min(a[1] - a[0], a[2] - a[1]);
	for(int i = 0; i < 2; ++i)
		if(a[i] + m != a[i+1])
		{
			printf("%d", a[i] + m);
			return 0;
		}
	if(a[0] - m >= -100)
		printf("%d", a[0] - m);
	else
		printf("%d", a[2] + m);
	return 0;
}

