//https://open.kattis.com/problems/busnumbers
#include <bits/stdc++.h>
using namespace std;

bool bus[1005];

int main() 
{
	int n;
	scanf("%d", &n);

	memset(bus, 0, sizeof(bus));

	int val;
	for(int i = 0; i < n; ++i)
		scanf("%d", &val), bus[val - 1] = 1;

	int len = 0;
	for(int i = 0; i <= 1000; ++i)
	{
		if(bus[i])
			++len;
		else if(len >= 2)
			printf("%d%c%d ", i + 1 - len, len == 2? ' ' : '-', i), len = 0;
		else if(len)
			printf("%d ", i), len = 0;
	}
	return 0;
}
