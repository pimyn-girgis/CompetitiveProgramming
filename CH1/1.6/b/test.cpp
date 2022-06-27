#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int n, x, total = 0;

int main()
{
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	for(int i = 0, j = n - 1; i <= j; --j, ++total)
		i += (arr[j] + arr[i] <= x);
	printf("%d", total);
	return 0;
}

