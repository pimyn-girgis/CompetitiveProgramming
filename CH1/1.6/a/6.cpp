#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, count = 0; char mode[5];
	bool plus, done;
	scanf("%d%s", &n, mode);
	int arr[n], ref[n], inRef[n];
	for(int i = 0; i < n; ++i)
		arr[i] = inRef[i] = i;
	plus = n%2;
	do
	{	
		for(int i = 0; i < n; ++i)
			ref[i] = arr[i];
		if(!strcmp(mode, "out"))
		{
			for(int i = 0; i < n/2; ++i)
			{
				arr[2*i] = ref[i];
				arr[2*i+1] = ref[n/2+i+plus];
			}
			if(plus) arr[n-1] = ref[n/2];
		}
		else
		{
			for(int i = 0; i < n/2; ++i)
			{
				arr[2*i] = ref[n/2+i];
				arr[2*i+1] = ref[i];
			}
		}
		++count;
		done = 1;
		for(int i = 0; i < n; ++i)
		{
			if(inRef[i] != arr[i])
				done = 0;
		}
	}while(!done);
	printf("%d", count);
	return 0;
}

