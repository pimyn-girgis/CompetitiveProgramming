#include <bits/stdc++.h>
using namespace std;

int m;
int arr[10000];

bool comp(int x, int y)
{
	int modx = x % m;
	int mody = y % m;

	if(modx != mody)
		return modx < mody;
	if(x % 2 && y % 2)
		return x > y;
	if(!(x % 2 || y % 2))
		return x < y;
	if(x%2)
		return 1;
	return 0;
}

int main()
{
	int n;

	while(scanf("%d %d", &n, &m) && (n || m))
	{
		for(int i=0;i<n;++i) scanf("%d", arr+i);
		sort(arr, arr+n, comp);
		printf("%d %d\n", n, m);
		for(int i=0;i<n;++i) printf("%d\n", arr[i]);
	}
	printf("0 0\n");

	return 0;
}
