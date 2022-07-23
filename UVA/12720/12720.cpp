#include <stdio.h>

char in[100005];
char out[100005];
int len;

int mod[100005];

int solve()
{
	int sum = 0;
	int mid = len / 2;
	out[len] = 0;
	int left = mid - 1, right = mid;

	if(len%2) out[--len] = in[mid], ++right;

	while(len)
		if(in[left--] == in[right++])
			out[--len] = out[--len] = in[left+1];
		else
			out[--len] = '1', out[--len] = '0';

	for(int i = 0;out[i];++i)
		sum += ((out[i] - '0') * mod[i]), sum %= 1000000007;
	return sum;
}

void init()
{
	mod[0] = 1;
	for(int i=1;i<1e5;++i)
		mod[i] = (mod[i-1] * 2) % 1000000007;
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	for(int i = 1;i <= t;++i)
	{
		scanf("%s%n", in, &len);
		--len;
		printf("Case #%d: %d\n",i, solve());
	}
	return 0;
}