#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<numeric>

using namespace std;
#define MAX 100000
#define SIZE 20 
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

	memcpy(arr+l, sub, ind*sizeof(int));
}

int main()
{
	int values[SIZE];
	iota(values, values+SIZE, 1);

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

		printf("After merge sort:\n");
		for(int i=0;i<n;++i) printf("%d%s", arr[i], i == n-1? "\n\n" : " ");

		printf("Inversion count = %lld\n", inversion_count);
		printf("------------------------------\n");

		delete[] arr;
	}

	return 0;
}

