//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	bool year[365] = {0};

	scanf("%d", &n);

	int from, to;
	while(n--)
		scanf("%d %d", &from, &to),
		memset(year + from - 1, 1, (to - from + 1) * sizeof(bool));

	printf("%ld\n", count(year, year + 365, 1));

	return 0;
}
