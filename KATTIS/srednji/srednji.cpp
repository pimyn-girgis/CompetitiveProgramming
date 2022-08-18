/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@aucegypt.edu
* Problem : srednji Kattis
* Link    : https://open.kattis.com/problems/srednji
**************************************************************
* Approach: 
* The main idea of that solution is that in order to have b as
* the median of some sequence, you need to have excatly n
* numbers smaller than b and exactly n numbers greater than b.
* 
* since you don't need the values of each number, but rather
* how they realte to b, simplyfying each number into -1 for
* smaller and 1 for greater makes sense.
* 
* Now, starting from b and going outwards in both directions
* (separately), we keep a running sum of the values, if the
* current sum is 0, the sequence contains n integers less than
* b and n integers greater than b, thus increase the current
* answer. Now, looking at the sums we have on each side, if 
* we have 3 sequences with sum -1 on the left side, and 5
* sequences with sum 1 on the right side, we can have 3 * 5
* sequences of sum 0.
* 
* add those to the answer and repeat with all values of
* running sums and you have your answer.
**************************************************************
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, b;
	scanf("%d %d", &n, &b);

	vector <int> arr(n);

	int pos = 0;
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		
		if(val == b) arr[i] = 0, pos = i;
		else arr[i] = val < b?  -1 : 1;
	}

	map <int, int> sumAfter;

	int curSum = 0;
	for(int i = pos + 1; i < n; ++i)
		++sumAfter[curSum += arr[i]];

	map <int, int> sumBefore;

	curSum = 0;
	for(int i = pos - 1; i >= 0; --i)
		++sumBefore[curSum += arr[i]];

	int ans = 1;
	ans += sumBefore[0] + sumAfter[0];

	for(auto u : sumAfter)
		ans += sumBefore[-u.first] * u.second;
	
	printf("%d\n", ans);
	
	return 0;
}
