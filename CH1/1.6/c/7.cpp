#include <bits/stdc++.h>
using namespace std;

int val, maxVal = 1e9, minVal = -1e9;
bool honest;
char judge[100];

int main()
{
	while(scanf("%d", &val) && val)
	{
		scanf("%s %s", judge, judge);
		if(!strcmp("high", judge))
			maxVal = min(maxVal, val);
		else if(!strcmp("low", judge))
			minVal = max(minVal, val);
		else
		{
			if(minVal < val && val < maxVal)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			maxVal = 1e9;
			minVal = -1e9;
		}
	}
	return 0;
}

