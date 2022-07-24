//https://open.kattis.com/problems/snapperhard
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n, k;
	scanf("%d", &t);
	for(int i=1;i<=t;++i)
	{
		int snap = 0;
		scanf("%d %d", &n, &k);
		n = (1 << n) - 1;
		bool on = (n & k) == n;
		printf("Case #%d: %s\n", i, on? "ON" : "OFF");
	}
	return 0;
}
