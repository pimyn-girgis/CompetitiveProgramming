#include <bits/stdc++.h>
using namespace std;

int arr[760][760];
int sum[750];
priority_queue <int, vector<int>, greater<int> > pq;

int main()
{
	int k;
	while (scanf("%d", &k) != EOF)
	{
		for(int i = 0; i < k; ++i)
			for(int j = 0; j < k; ++j)
				scanf("%d", arr[i]+j);

		memset(sum, 0, sizeof(sum));
		
		for(int i = 0; i < k; ++i)
			sort(arr[i], arr[i] + k);
	}
	return 0;
}
