#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, n;
	scanf("%d%d%d%d", &a, &b, &c, &n);
	if (a > 0 && b > 0 && c > 0 && n > 2 && n <=  a+b+c)
		printf("YES");
	else
		printf("NO");
	return 0;
}

