#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		bool turn = 1;
		long long int a = 0, b = 0;
		for(int i=0;i<32;++i, n >>= 1)
		{
			if(n & 1)
			{
				if(turn) a |= (int(1) << i);
				else b |= (int(1) << i);
				turn = !turn;
			}
		}
		printf("%lld %lld\n", a, b);
	}
	return 0;
}
