#include <bits/stdc++.h>
using namespace std;

int main()
{
	char ans[1000005];
	int n, m;
	while(scanf("%s%n", ans, &n) != EOF)
	{
		--n;
		if(!strcmp(ans, "END"))
			return 0;
		m = 2;
		if(n == 1&& atoi(ans) == 1)
			m = 1;
		while(n > 1)
		{
			m++;
			n = to_string(n).size();
		}
		printf("%d\n", m);
	}
	return 0;
}
