#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char x [100] = "\0";
		char a [5] = "\0";
		char b [5] = "\0";
		scanf("%s", x);
		if(!strcmp(x, "P=NP"))
			printf("skipped\n");
		else
		{
			int k;
			for(int i = 0; i < 6; ++i)
				if(x[i-1] != '+')
					a[i-1] = x[i-1];
				else
				{k = i; break;}
			for(int i = 0; i < 6;++i)
				if(x[i+k] != '\0')
					b[i] = x[i+k];
				else
					break;
			printf("%d\n", atoi(a) + atoi(b));
		}
	}
	return 0;
}

