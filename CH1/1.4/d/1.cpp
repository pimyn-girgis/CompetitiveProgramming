#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &x);
		if(x%2)
			printf("%d is odd\n", x);
		else
			printf("%d is even\n", x);
	}
	return 0;
}

