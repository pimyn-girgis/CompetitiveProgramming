#include <bits/stdc++.h>
using namespace std;

bitset<1445> busy;

bool solve()
{
	int sh, eh, sm, em, start, end;
	scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
	start = sh*60+sm, end = eh*60+em;
	for(int i=start;i<=end;++i) busy.set(i);
	scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
	start = sh*60+sm, end = eh*60+em;
	for(int i=start;i<=end;++i) if(busy[i]) return 0;
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		busy.reset();
		printf("Case %d: %s Meeting\n", i, solve()? "Hits" : "Mrs");
	}
	return 0;
}
