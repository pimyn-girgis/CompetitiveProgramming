#include <bits/stdc++.h>
using namespace std;

char road[60];
bitset <55> possible;

int ans()
{
	int val=0;
	for(int i=0;road[i];++i)
		val += possible.test(i);
	return val;
}
void solve()
{
	for(int i=0;road[i];++i)
	{
		const char val = road[i];
		if(val != '-') possible.reset(i);
		if(val == 'B') 
		{
			if(i-1 >= 0) possible.reset(i-1);
			if(i-2 >= 0) possible.reset(i-2);
		}
		else if(val == 'S')
		{
			possible.reset(i+1);
			if(i-1 >= 0) possible.reset(i-1);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;++i)
	{
		possible.set();
		scanf("%s", road);
		solve();
		printf("Case %d: %d\n", i, ans());
	}
	return 0;
}

