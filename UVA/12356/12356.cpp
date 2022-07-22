#include <bits/stdc++.h>

#define maxsize int(1e5 + 1)

int left[maxsize];
int right[maxsize];
std::bitset<maxsize> alive;

void init(int s)
{
	alive.set();
	std::iota(left+1, left+s+1, 0);
	std::iota(right+1, right+s, 2);
	right[s] = 0;
}

int onLeft(int cur)
{
	int val = left[cur];
	return alive[val]? val : onLeft(val);
}

int onRight(int cur)
{
	int val = right[cur];
	return alive[val]? val : onRight(val);
}

void die(int l, int r)
{
	for(int i=l;i<=r;++i)
		alive.reset(i);
	for(int i=r-1;i>l;--i)
		right[i]=onRight(r);
	for(int i=l+1;i<=r+1;++i)
		left[i]=onLeft(l);
}

void output(int l, int r)
{
	int leftVal = onLeft(l), rightVal = onRight(r);
	if(leftVal) printf("%d ", leftVal);
	else printf("* ");
	if(rightVal) printf("%d\n", rightVal);
	else printf("*\n");
}

int main()
{
	int s, b, l, r;
	while(scanf("%d %d", &s, &b) && s && b)
	{
		init(s);
		for(int i=0;i<b;++i)
		{
			scanf("%d %d", &l, &r);
			die(l, r);
			output(l, r);
		}
			puts("-");
	}
	return 0;
}