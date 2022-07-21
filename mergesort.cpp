#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<time.h>

using namespace std;
#define MAX 100000
#define ll long long int

int sub[MAX];
ll inversion_count;

void mergesort(int *arr, int l, int r)
{
	if(l == r) return;

	int m = (l+r)/2;
	mergesort(arr, l, m);
	mergesort(arr, m+1, r);

	int i = l, j = m+1, ind = 0;
	while(i <= m && j <= r)
		if(arr[i] < arr[j]) sub[ind++] = arr[i++];
		else sub[ind++] = arr[j++], inversion_count += m - i + 1;
	while(i <= m)
		sub[ind++] = arr[i++];
	while(j <= r)
		sub[ind++] = arr[j++];

	memcpy(arr+l, sub, ind*(sizeof(int)));
}

int main()
{
	int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	for(auto &n : values)
	{
		if(n <= 0) continue;

		inversion_count = 0;
		int *arr = new int[n];
	
		srand(time(0));
	
		for(int i=0;i<n;++i) arr[i] = rand() % 2000;
	
		printf("Array of size %d before merge sort:\n", n);

		for(int i=0;i<n;++i) printf("%d%s", arr[i], i == n-1? "\n\n" : " ");

		mergesort(arr, 0, n-1);

		printf("Inversion count = %lld\n\n", inversion_count);
	
		printf("After merge sort:\n");
		for(int i=0;i<n;++i) printf("%d%s", arr[i], i == n-1? "\n" : " ");

		printf("------------------------------\n");

		delete[] arr;
	}

	return 0; }

