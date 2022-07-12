#include <bits/stdc++.h>
using namespace std;

vector<int> arr(20);
int sum;

void init()
{
	fill(arr.begin(), arr.end(), 0);
	sum = 0;
}

void solve()
{
	for(int i=1;i<20;++i)
	{
		int key = arr[i];
		int j;
		for(j=i-1;j>=0 && arr[j] > key;--j)
		{
			arr[j+1] = arr[j];
			++sum;
		}
		arr[j+1] = key;
	}
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
