//https://open.kattis.com/problems/bookingaroom
#include <bits/stdc++.h>
using namespace std;

bitset<105> available;

int main() 
{
	int n, r;
	scanf("%d %d", &r, &n);

	available.set();
	int val;

	while(n--)
		scanf("%d", &val), available.reset(val - 1);

	for(int i = 0; i < r; ++i)
		if(available.test(i))
		{
			printf("%d\n", i + 1);
			break;
		}
		else if(i == r - 1)
			printf("too late\n");


	return 0;
}
