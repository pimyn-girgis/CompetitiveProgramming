#include <bits/stdc++.h>
using namespace std;

int n, arr[3000];
bool val[3000];

bool jolly()
{
	for(int i=1;i<n;++i)
		int dif = abs(arr[i-1] - arr[i]), val[dif-1] |= (dif < n);

	for(int i=0;i<n-1;++i)
		if(!val[i])
			return 0;

	return 1;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(val, 0, sizeof(val));

		for(int i=0;i<n;++i)
			scanf("%d", arr+i);

		printf("%s", jolly()? "Jolly\n" : "Not jolly\n");
	}

	return 0;
}