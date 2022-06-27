#include <bits/stdc++.h>
using namespace std;

bool exist(int num, int arr[], int size)
{
	for(int i = 0; i < size && num >= arr[i]; ++i)
		if(num == arr[i])
			return 1;
	return 0;
}
int main()
{
	int a, b, val, A[10005], in, count, prev;

	while(scanf("%d%d", &a, &b))
	{
		if(!a && !b)
			return 0;
		in = count = val = 0;
		while(a--)
		{
			scanf("%d", &val);
			if(in && val > A[in-1])
				A[in++] = val;
			else if(!in)
				A[in++] = val;
		}
		a = in;
		in = 0;
		while(b--)
		{
			scanf("%d", &val);
			if((in && val > prev) || !in)
			{
				++in;
				if(exist(val, A, a))
					++count;
			}
			prev = val;
		}
		printf("%d\n", min(a, in) - count);
	}
	return 0;
}

