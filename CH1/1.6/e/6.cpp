#include <bits/stdc++.h>
using namespace std;

int main()
{
	int begin, end, ans, val, absVal;
	scanf("%d %d", &begin, &end);
	val = end - begin;
	absVal = abs(val);
	if(absVal < 180)
		ans = val;
	else if(absVal == 180)
		ans = 180;
	else if(val < 0)
		ans = 360 + val;
	else if(val > 0)
		ans = val - 360;
	printf("%d", ans);
	return 0;
}

