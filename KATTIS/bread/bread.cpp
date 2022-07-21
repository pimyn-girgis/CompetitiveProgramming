#include <bits/stdc++.h>
using namespace std;

#define maxsize 100000

int sorted[maxsize];
int arr[maxsize];
int sub[maxsize];
int inversion_count = 0;
int n;

void sort(int *arr, int l, int r)
{
	if(l == r) return;

	int m = (l+r)/2;
	sort(arr, l, m);
	sort(arr, m+1, r);

	int i=l, j=m+1, ind = 0;

	while(i <= m && j <= r)
		if(arr[i] < arr[j]) sub[ind++] = arr[i++];
		else sub[ind++] = arr[j++], inversion_count += m - i + 1;
	while(i <= m)
		sub[ind++] = arr[i++];
	while(j <= r)
		sub[ind++] = arr[j++];
	
	memcpy(arr+l, sub, ind*sizeof(int));
}

int main() 
{
	int val;
	scanf("%d", &n);
	for(int i=0;i<n;++i) scanf("%d", arr+i);
	for(int i=0;i<n;++i) scanf("%d", sorted+i);

	inversion_count = 0;
	sort(arr, 0, n-1);
	int in1 = inversion_count;
	inversion_count = 0;
	sort(sorted, 0, n-1);
	int in2 = inversion_count;
	printf((in1+in2)%2? "Impossible\n" : "Possible\n");
	return 0;
}