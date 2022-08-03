#include <bits/stdc++.h>
using namespace std;

int sum[int(1e6)];
int arr[755][755];
int k;

void makeSet(int index, int setNum)
{
	if(index == k - 1) return;

	for(int i = 0; i < k; ++i)
	{
		sum[index] += arr[ ]
	}
}

int main()
{
	while (scanf("%d", &k) != EOF)
	{
		memset(sum, 0, k * k * sizeof(int));

		for(int i = 0; i < k; ++i)
			for(int j = 0; j < k; ++j)
				scanf("%d", arr[i] + j);

		calc(0, 0);
	}
	return 0;
}