/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@aucegypt.edu
* Problem : 11997 UVA
* Link    : https://onlinejudge.org/external/119/p11997.pdf
**************************************************************
* Approach: 
* Imagine the most trivial case where we only have 2 arrays
* a, b. The k smallest sums of these 2 arrays can be obtained
* by calculating all possible sums:
* 	a1 + b1, a1 + b2, a1 + b3, ....
* 	a2 + b1, a2 + b2, a2 + b3, ....
* 	.. . ..  .. . ..  .. . ..  ....
* 	.. . ..  .. . ..  .. . ..  ....
* 	.. . ..  .. . ..  .. . ..  ....
* 
* Now, by partially sorting the obtained array of size k^2 we 
* obtain the k smallest sums in O(k^2 log(k)).
* 
* Now, to get the smallest possible sums of k = 750 arrays, we can
* either repeat the exact same process which would be achived in
* 750^750 log(750), a ridiculously large complexity. Or, the more
* realisitic approach, is to notice that to obtain the k smallest
* sums of k arrays, you need the k smallest sums of each 2 arrays.
* You can then use the k smallest sums of the first 2 arrays as an
* array in itself, reducing the overall complexity to O(K^3 log(K));
* An attainable complexity with a maximum value k = 750.
**************************************************************
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 755
unsigned int arr1[MAX], arr2[MAX], sum[MAX * MAX];
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