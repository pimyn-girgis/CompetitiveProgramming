#include <bits/stdc++.h>
using namespace std;

vector<int> arr(20);
int sum;
#define n 20

void init()
{
	fill(arr.begin(), arr.end(), 0);
	sum = 0;
}

void solve()
{
	for(int i=1;i<n;++i)
		for(int j=i;j>=0;--j)
			if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]), ++sum;
}

int main() 
{
	int p, test;
	scanf("%d", &p);
	while(p--)
	{
		init();
		scanf("%d", &test);
		for(auto &u : arr) scanf("%d", &u);
		solve();
		printf("%d %d\n", test, sum);
	}
	return 0;
}
