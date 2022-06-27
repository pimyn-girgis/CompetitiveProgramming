#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, sum = 0;
	scanf("%d", &m);
	n = m;
	while(m--)
	{
		scanf("%d", &k);
		if(k != -1)
			sum += k;
		else --n;
	}
	printf("%f", float(sum)/n);
	return 0;
}

