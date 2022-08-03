//https://open.kattis.com/problems/jugglingpatterns
#include <bits/stdc++.h>
using namespace std;

char pattern[1005];

int main() 
{
	while(scanf("%s", pattern) != EOF)
	{
		int sum = 0;
		int count = 0;

		for(auto &u : pattern)
			if(!u) break;
			else ++count, sum += u - '0';

		bool invalid = sum % count;

		if(invalid) printf("%s: invalid # of balls\n", pattern);
		else
		{
			int balls = sum / count;
			invalid = 0;

			for(int i = 0; i < count; ++i)
			{
			}

			if(invalid) printf("%s: invalid pattern\n", pattern);
			else printf("%s: valid with %d balls\n", pattern, balls);
		}
	}
	return 0;
}
