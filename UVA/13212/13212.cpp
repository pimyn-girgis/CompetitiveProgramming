#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int arr[MAX];
int sub[MAX];
long long int inversions_count;

void sort(int l, int r)
{
	if(l == r) return;

	int m = (l+r)/2;
	sort(l, m);
	sort(m+1, r);

	int i=l, j=m+1, ind=0;
	while(i <= m && j <= r)
		if(arr[i] < arr[j]) sub[ind++] = arr[i++];
		else sub[ind++] = arr[j++], inversions_count += (m - i + 1);
	while(i <= m)
		sub[ind++] = arr[i++];
	while(j <= r)
		sub[ind++] = arr[j++];

	memcpy(arr+l, sub, ind*sizeof(int));
}

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		inversions_count = 0;
		for(int i = 0;i < n;++i) scanf("%d", arr+i);
		sort(0, n-1);
		printf("%lld\n", inversions_count);
	}
	
	return 0;
}
