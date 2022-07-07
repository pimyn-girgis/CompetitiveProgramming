#include <bits/stdc++.h>
using namespace std;

char deck[53][5];
int n, pos;
bitset<53> done;

void init(){done.reset(); pos = 0;}

void solve(char *card, char *num)
{
	int len = strlen(num);
	for(;;++pos)
	{
		pos %= n;
		if(!done[pos]) --len;
		if(!len)
		{
			strcpy(deck[pos], card);
			done.set(pos);
			return;
		}
	}
}

void output()
{
	for(int i=0;i<n;++i)
		printf(n-i-1? "%s " : "%s\n", deck[i]);
}

int main() {
	char card[5], num[30];
	while(scanf("%d", &n) && n)
	{
		init();
		for(int i=1;i<=n;++i)
		{
			scanf("%s%s", card, num);
			solve(card, num);
		}
		output();
	}
	return 0;
}