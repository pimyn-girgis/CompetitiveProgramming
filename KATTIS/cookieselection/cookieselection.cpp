/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : cookieselection Kattis
* Link    : https://open.kattis.com/problems/cookieselection
**************************************************************
* Approach: 
* By inserting the elements into an OST, we can access the me-
* dian in O(1 ~ 3) since you always check the root first
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

//must use less_equal to ensure multiset-like capabilities.
typedef tree <int , null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

ost cookie;

void printErase(int pos)
{
	auto it = cookie.find_by_order(pos);
	printf("%d\n", *it);
	cookie.erase(it);
}

int main()
{
	char input[15];

	while(scanf("%s", input) != EOF)
	{
		if(isdigit(input[0]))
			cookie.insert(atoi(input));
		else if(cookie.size() & 1)
			printErase((cookie.size() + 1) / 2 - 1);
		else
			printErase((cookie.size() / 2));
	}
	return 0;
}
