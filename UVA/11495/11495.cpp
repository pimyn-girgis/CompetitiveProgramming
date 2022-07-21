#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define ll long long int
int sub[MAX];
int arr[MAX];
int marcelo;

void mergesort(int l, int r)
{
	if(l == r) return;

	int m = (l+r)/2;
	mergesort(l, m);
	mergesort(m+1, r);

	int i = l, j = m+1, ind = 0;

	while(i <= m && j <= r)
		if(arr[i] <= arr[j]) sub[ind++] = arr[i++];
		else sub[ind++] = arr[j++], marcelo += m - i + 1;
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
		marcelo = 0;
		for(int i=0;i<n;++i) scanf("%d", arr+i);
		mergesort(0, n-1);
		printf("%s\n", marcelo%2? "Marcelo" : "Carlos");
	}
	return 0;
}
