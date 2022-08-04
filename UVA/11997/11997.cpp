#include <bits/stdc++.h>
using namespace std;

#define MAX 755
int arr1[MAX], arr2[MAX], sum[MAX * MAX];
int k;

int main()
{
	while (scanf("%d", &k) != EOF)
	{
		for(int i = 0; i < k; ++i)
			scanf("%d", sum + i);

		for(int m = 1; m < k; ++m)
		{
			memcpy(arr1, sum, k * sizeof(int));

			for(int i = 0; i < k; ++i)
				scanf("%d", arr2 + i);

			for(int i = 0, index = 0; i < k; ++i)
				for(int j = 0; j < k; ++j, ++index)
					sum[index] = arr1[i] + arr2[j];

			partial_sort(sum, sum + k, sum + k * k);
		}

		for(int i = 0; i < k; ++i)
			printf("%d%c", sum[i], i == k - 1? '\n' : ' ');
	}
	return 0;
}