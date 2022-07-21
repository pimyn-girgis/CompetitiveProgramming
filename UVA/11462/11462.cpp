#include <bits/stdc++.h>
using namespace std;

int arr[2000005];
int age[100];

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{
		int index = 0;
		memset(age, 0, sizeof(age));

		for(int i=0;i<n;++i)
			scanf("%d", arr+i), ++age[arr[i]-1];

		for(int i=0;i<100;++i)
			while(age[i]--)
				arr[index++] = i+1;

		for(int i=0;i<n;++i)
			printf("%d%c", arr[i], i == n - 1? '\n' : ' ');
	}
	return 0;
}