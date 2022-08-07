//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	map <set <int>, int> course;

	int maxVal = 0;
	for(int i = 0; i < n; ++i)
	{
		int val;
		set <int> comb;

		for(int j = 0; j < 5; ++j)
			scanf("%d", &val), comb.insert(val);

		maxVal = max(++course[comb], maxVal);
	}

	int ans = 0;
	for(auto it = course.begin(); it != course.end(); ++it)
		ans += it->second * (it->second == maxVal);
	
	printf("%d\n", ans);
	
	return 0;
}
