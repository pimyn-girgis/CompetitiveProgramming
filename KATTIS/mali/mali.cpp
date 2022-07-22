#include <bits/stdc++.h>
using namespace std;

#define size 100
int a[size], b[size], n;

int solve(int l, int r, int aval, int bval)
{
	//printf("%d %d %d %d\n", l, r, aval, bval);
	int maxVal = 0;
	
	while(!aval && l < size) aval = a[l++];
	while(!bval && r >= 0) bval = b[r--];

	int dif = min(bval, aval);
	bval -= dif;
	aval -= dif;

	if(l >= size && r < 0)
		return 0;
	return max(2 + l + r, solve(l, r, aval, bval));
}

int main() 
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int aval, bval;
	
	scanf("%d", &n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d", &aval, &bval);
		++a[aval-1], ++b[bval-1];
		printf("%d\n", solve(0, size-1, 0, 0));
	}
	
	return 0;
}