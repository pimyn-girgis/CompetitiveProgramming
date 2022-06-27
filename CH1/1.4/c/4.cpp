#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	if(n == m + 1)
		printf("Dr. Chaz will have 1 piece of chicken left over!");
	else if(m < n)
		printf("Dr. Chaz will have %d pieces of chicken left over!", n - m);
	else if(m == n+1)
		printf("Dr. Chaz needs 1 more piece of chicken!");
	else
		printf("Dr. Chaz needs %d more pieces of chicken!", m - n);
	return 0;
}

