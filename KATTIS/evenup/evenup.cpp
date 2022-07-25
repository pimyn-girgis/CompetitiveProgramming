//https://open.kattis.com/problems/evenup
#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int deck[MAX];

int top = -1;

int main() 
{
	int n, in;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", deck + ++top);
		if(top <= 0) continue;

		if((deck[top] & 1) == (deck[top-1] & 1))
			top -= 2;
	}
	printf("%d\n", top + 1);
	return 0;
}
