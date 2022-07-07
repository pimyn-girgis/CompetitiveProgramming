#include <bits/stdc++.h>
using namespace std;

int problems[10001];
int uni[100];

void init()
{
	for(int i=0;i<10001;++i) problems[i] = 1;
	memset(uni,0, sizeof(uni));
}

void solve()
{
	for(int i=1;i<=10000;++i)
		++uni[problems[i]];
}

void output(int t)
{
	int *maxE = max_element(uni+3, uni+6);
	int max = *maxE;
	int total = uni[max];
	printf("Case #%d:\n", t);
	for(int i=3;i<6;++i)
	{
		if(uni[i] == max)
		{
			printf("%d %d", i-2, max);
			for(int j=0;j<10001;++j)
				if(problems[j] == i)
					printf(" %d", j);
			printf("\n");
		}
	}
}

int main()
{
	int t, val, prob;
	scanf("%d", &t);
	for(int test=1;test<=t;++test)
	{
		init();
		for(int i=3;i<=5;++i)
		{
			scanf("%d", &val);
			while(val--)
			{
				scanf("%d", &prob);
				if(problems[prob] % i)
					problems[prob] *= i;
			}
		}
		solve();
		output(test);
	}
	return 0;
}
/*
4 3 1 2 3 4 4 5 6 7 5 8 9 10 11 12 2 1 5 2 2 3 3 2 3 1 6 400 401 402 403 404 405 2 101 100 7 400 401 402 403 404 405 406 1 1 1 2 1 3
*/