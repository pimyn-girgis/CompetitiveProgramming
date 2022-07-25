//https://open.kattis.com/problems/primaryarithmetic
#include <bits/stdc++.h>
using namespace std;

int x, y;

int carry;

int main() 
{
	while(scanf("%d %d", &x, &y), x || y)
	{
		solve();

		if(!carry) printf("No carry operation.\n");
		else if(carry == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", carry);
	}
}
