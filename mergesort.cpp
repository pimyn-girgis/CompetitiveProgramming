#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<iostream>
#include<vector>

using namespace std;

void merge(int *arr, int begin, int mid, int end)
{
	int const leftSize = mid - begin +1; //size of left sub_array
	int left[leftSize];

	int const rightSize = end - mid; //size of right sub_array
	int right[rightSize];

	for(int i=0;i<leftSize;++i) left[i] = arr[begin+i]; //populate left sub_array

	for(int i=0;i<rightSize;++i) right[i] = arr[mid+i+1]; //populate right sub_array

	for(int i=begin, rightIndex=0, leftIndex=0;i<= end;++i) //sort the array
		if(rightIndex < rightSize && leftIndex < leftSize)
			arr[i] = (right[rightIndex] < left[leftIndex])? right[rightIndex++] : left[leftIndex++];
		else if(rightIndex < rightSize)
			arr[i] = right[rightIndex++];
		else
			arr[i] = left[leftIndex++];
}

void mergesort(int *arr, int begin, int end)
{
	if(end <= begin) return;

	int mid = (end + begin) / 2;
	mergesort(arr, begin, mid);
	mergesort(arr, mid+1, end);
	merge(arr, begin, mid, end);
}

void mergesort(int *arr, int size){mergesort(arr, 0, size-1);}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{

		int *arr = new int[n];
	
		srand(time(0));
	
		for(int i=0;i<n;++i) arr[i] = rand() % 2000;
	
		printf("Array of size %d before merge sort:\n", n);

		for(int i=0;i<n;++i) printf("%d%s", arr[i], i == n-1? "\n\n" : " ");
	
		mergesort(arr, n);
	
		printf("After merge sort:\n");
		for(int i=0;i<n;++i) printf("%d%s", arr[i], i == n-1? "\n" : " ");

		printf("------------------------------\n");

		delete[] arr;
	}

	return 0; }

