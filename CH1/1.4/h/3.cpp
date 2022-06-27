#include <bits/stdc++.h>
using namespace std;

int main()
{
	char c [41];
	char d [11];
	int n, k;
	scanf("%d", &n);
	for(int i = 0; i < 5; ++i)
	{
		scanf("%s", c);
		if(i == 3)
		{
			k = 0;
			for(int j = 0; j < strlen(c); j+= 4)
			{
				if(c[j] == '*')
					d[k] = '2';
				else if(c[j+1] == '*')
					d[k] = '1';
				else if(c[j+2] == '*')
					d[k] = '3';
				++k;
			}
			d[k] = '\0';
		}
	}
		printf("%s\n", d);
	return 0;
}

