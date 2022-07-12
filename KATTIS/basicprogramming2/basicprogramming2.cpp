#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int arr[200005];
int n;

void xplusy()
{
	long long unsigned int sum;
	for(int i=0, j=n-1;i<j;)
	{
		sum = arr[i] + arr[j];
		if(sum == 7777)
		{
			printf("Yes\n");
			return;
		}
		else if(sum < 7777)
			++i;
		else
			--j;
	}
	printf("No\n");
}

void unique()
{
	for(int i=0;i<n-1;++i)
		if(arr[i] == arr[i+1])
		{
			printf("Contains duplicate\n");
			return;
		}
	printf("Unique\n");
}

void over_n()
{
	unordered_map<int, int> map;
	for(int i=0;i<n;++i)
	{
		++map[arr[i]];
		if(map[arr[i]] > n/2)
		{
			printf("%d\n", arr[i]);
			return;
		}
	}
	printf("-1\n");
}

void med()
{
	if(n%2) printf("%d\n", arr[n/2]);
	else printf("%d %d\n", arr[n/2-1], arr[n/2]);
}

void print()
{
	bool first = 0;
	for(int i=0;i < n && arr[i]<= 999;++i)
		if(arr[i] >= 100)
			printf(first? " %d" : "%d", arr[i]), first = 1;
	printf("\n");
}

void solve(int t)
{
	sort(arr, arr+n);
	if(t == 1) xplusy();
	else if(t == 2) unique();
	else if(t == 3) over_n();
	else if(t == 4) med();
	else print();
}

int main() 
{
	int t;
	scanf("%d %d", &n, &t);
	for(int i=0;i<n;++i) scanf("%d", arr+i);
	solve(t);
	return 0;
}
