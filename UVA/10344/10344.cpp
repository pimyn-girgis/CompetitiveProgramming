/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10344 UVA
* Link    : https://onlinejudge.org/external/103/p10344.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int val[5];
char per[5];
char op[] = "+-*";

int calc(int a, int b, char op)
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
	}

	return 0;
}

bool test()
{
	int temp = val[0];

	for(int i = 1; i < 5; ++i)
		temp = calc(temp, val[i], per[i - 1]);
	
	return temp == 23;
}

bool solve(int len)
{
	if(!len) return test();

	for(char *c = op; *c; ++c)
	{
		per[len - 1] = *c;
		if(solve(len - 1))
			return true;
	}
	
	return false;
}

bool solve()
{
	sort(val, val + 5);
	do
	{
		if(solve(4))
			return true;
	} while (next_permutation(val, val + 5));

	return false;
}

int main()
{
	while(true)
	{
		for(int i = 0; i < 5; ++i)
			scanf("%d%*c", val + i);

		if(!val[0]) break;

		printf("%s\n", solve()? "Possible" : "Impossible");
	}
	
	return 0;
}
