#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a [31];
	char b [31];
	char c [31];
	int i, n;
	scanf("%d", &i);
	while(i--)
	{
		scanf("%s%s%s%d", a, b, c, &n);
		if(strcmp("2010/01/01", b) <= 0 || strcmp("1991/01/01", c) <= 0)
			printf("%s eligible", a);
		else if(n > 40)
			printf("%s ineligible", a);
		else
			printf("%s coach petitions", a);
		printf("\n");
	}
	return 0;
}

