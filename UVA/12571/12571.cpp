#include <bits/stdc++.h>
using namespace std;


int x[100000];
int ans[235];
int n;

void precalc()
{
	memset(ans, 0, sizeof(ans));

	for(int i=0;i<230;++i)
		for(int j=0;j<n;++j)
			ans[i] = max(ans[i], x[j] & i);
}

int main()
{
	int t, q, val;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &q);
		for(int i=0;i<n;++i) scanf("%d", x+i);
		precalc();
		while(q--) scanf("%d", &val), printf("%d\n", ans[val]);
	}
	return 0;
}
