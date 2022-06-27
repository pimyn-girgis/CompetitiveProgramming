#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a = 2, b;
	scanf("%d", &b);
	while(b--)
		a = 2*a - 1;
	printf("%d", a*a);
	return 0;
}
