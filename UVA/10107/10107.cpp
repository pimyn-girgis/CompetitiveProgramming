#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main()
{
	int k=0;
	while(scanf("%d", arr+(k++)) != EOF)
	{
		nth_element(arr, arr + k/2, arr+k);
		if(k%2) printf("%d\n", arr[k/2]);
		else
		{
			nth_element(arr, arr+ k/2-1, arr+k);
			printf("%d\n", (arr[k/2-1]+arr[k/2])/2);
		}
	}
	return 0;
}
