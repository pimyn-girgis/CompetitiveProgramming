#include <bits/stdc++.h>
using namespace std;

int train[1005];

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int val;
		while(scanf("%d", &val), val)
		{
			int top = -1;
			int k = 0;
			for(int i = 1;i <= n;++i)
			{
				if(i != 1) scanf("%d", &val);

				while(k < val)
					train[++top] = ++k;
	
				if(top >= 0 && train[top] == val)
					--top;
			}
	
			if(top == -1) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	
	return 0;
}