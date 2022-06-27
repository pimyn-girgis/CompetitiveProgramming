#include <bits/stdc++.h>
using namespace std;

int n, k, num, p[100], win[100], lose[100], in1, in2, ans;
char mv1[15], mv2[15];
double avg[100];

void reset()
{
	memset(p, 0, sizeof(p));
	memset(lose, 0, sizeof(lose));
	memset(win, 0, sizeof(win));
	memset(avg, 0, sizeof(avg));
	num = k * n * (n - 1) / 2;
}

void game()
{
	if(!strcmp(mv1, mv2))
		return;
	else if(mv1[0] == 'r' && mv2[0] == 's'
		  ||mv1[0] == 'p' && mv2[0] == 'r'
		  ||mv1[0] == 's' && mv2[0] == 'p')
		++win[in1-1], ++lose[in2-1];
	else
		++win[in2-1], ++lose[in1-1];
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		scanf("%d", &k);
		reset();
		while(num--)
		{
			scanf("%d %s %d %s", &in1, mv1, &in2, mv2);
			game();
		}
		for(int i = 0; i < n; ++i)
			if(win[i] + lose[i])
				printf("%.3f\n", float(win[i])/(lose[i] + win[i]));
			else
				printf("-\n");
		printf("\n");
	}
	return 0;
}

