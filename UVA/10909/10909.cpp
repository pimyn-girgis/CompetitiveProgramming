/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10909 UVA
* Link    : https://onlinejudge.org/external/109/p10909.pdf
**************************************************************
* Approach: 
* Initialize the lucky numbers using an order statistics tree.
* If the input number is odd, it does not equal the sum of any
* two lucky numbers (odd + odd != odd).
* Otherwise __see code ln 47, self explanatory!__
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define MAX 2000001

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;
ost lucky;

void init()
{
	//first insert all odd numbers until MAX (2000001).
	//equivalent to inserting all numbers and deleting every second
	for(int i = 1; i < MAX; i += 2)
		lucky.insert(i);

	//start at *cur = 3, erase every third number.
	//repeat the step with the next lucky number (7), and keep repeating.
	for(auto cur = ++lucky.begin(); cur != lucky.end() && *cur <= lucky.size(); ++cur)
		for(int i = *cur - 1; i <= lucky.size(); i += (*cur - 1))
			lucky.erase(lucky.find_by_order(i));
}

int main()
{
	init();

	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n & 1)
			printf("%d is not the sum of two luckies!\n", n);
		else
		{
			auto first = lucky.upper_bound(n / 2);
			auto second = lucky.lower_bound(n / 2);
	
			while(*first + *second != n && *second < n && *first > 1 && second != lucky.end() && first != --lucky.begin())
				if(*first + *second < n)
					++second;
				else if(*first + *second > n)
					--first;
	
			if(*first + *second == n)
				printf("%d is the sum of %d and %d.\n", n, *first, *second);
			else
				printf("%d is not the sum of two luckies!\n", n);
		}
	}

	return 0;
}
