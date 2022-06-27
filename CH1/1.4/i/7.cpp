#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, a, b, ans;
	scanf("%d", &t);
	while(t--)
	{
		a = 0; b = 0;
		scanf("%d", &n);
		int* v = new int [n];
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			a += v[i];
			b = max(b, v[i]);
			ans = b == v[i]? i : ans;
		}
		++ans;
		sort(&v[0], &v[n]);
		if(v[n-1] == v[n-2])
			printf("no winner\n");
		else if(v[n-1] > a/2)
			printf("majority winner %d\n", ans);
		else 
			printf("minority winner %d\n", ans);
	}
	return 0;
}

