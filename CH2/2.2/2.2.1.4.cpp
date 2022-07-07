#include <bits/stdc++.h>
//using namespace std;

#define SIZE 4

void rotate(char arr[SIZE][SIZE], char rot[SIZE][SIZE])
{
	for(int i=0;i<SIZE;++i)
		for(int j=0;j<SIZE;++j)
			rot[i][j] = arr[j][i];

	for(int i=0;i<SIZE/2;++i)
		std::swap(rot[i], rot[SIZE-i-1]);
}

void transpose(char arr[SIZE][SIZE])
{
	char trans[SIZE][SIZE];

	for(int i=0;i<SIZE;++i)
		for(int j=0;j<SIZE;++j)
			return;
}

int main()
{
	char arr[SIZE][SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
	char rot[SIZE][SIZE];
	char trans[SIZE][SIZE];
	for(int i=0;i<SIZE;++i,printf("\n"))
		for(int j=0;j<SIZE;++j)
			printf("%c ", arr[i][j]);

	printf("\n");
	
	rotate(arr, rot);

	for(int i=0;i<SIZE;++i,printf("\n"))
		for(int j=0;j<SIZE;++j)
			printf("%c ", rot[i][j]);
	return 0;
}