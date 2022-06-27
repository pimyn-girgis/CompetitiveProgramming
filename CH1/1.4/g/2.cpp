#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;char a[80];
	scanf("%d", &t);
	while(t--)
	{
		int i = 0, m = 0;
		scanf("%s", a);
		for(int j = 0; a[j] != '\0';++j)
		{
			if(a[j] == 'X')
				i = 0;
			else
				++i;
			m += i;
		}
		printf("%d\n", m);
	}
	return 0;
}

