/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : Books
* Link    : https://codeforces.com/problemset/problem/279/B
**************************************************************
* Approach: Two pointers
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int books[int(1e5 + 5)];

int main()
{
	int t, n;
	scanf("%d %d", &n, &t);

	for(int i = 0; i < n; ++i)
		scanf("%d", books + i);

	int max_num = 0;
	int sum = 0;

	for(int i = 0, j = 0; j < n; ++j)
	{
		sum += books[j];
		if(sum > t)
			sum -= books[i++];
		else
			max_num = max(j - i + 1,  max_num);
	}
	
	printf("%d\n", max_num);

	return 0;
}