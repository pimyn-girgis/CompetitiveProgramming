#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k = 0;
	float l, w, h, m;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%f%f%f%f", &l, &w, &h, &m);
		if(m <= 7 && (l+w+h <= 125 || l <= 56 && w <= 45 && h <= 25))
		{
			printf("1\n");
			++k;
		}
		else
			printf("0\n");
	}
	printf("%d\n", k);
	return 0;
}