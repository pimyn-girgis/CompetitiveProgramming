#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; float x, y, z = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%f%f", &x, &y);
		z += x * y;
	}
	printf("%f", z);
	return 0;
}

