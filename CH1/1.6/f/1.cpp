#include <bits/stdc++.h>
using namespace std;

char num[15];

void solve(int index)
{
	int val = num[index] - '0';
	val *= 2;
	if(val > 9)
		val = val % 10 + 1;
	num[index] = val + '0';
}

int main()
{
	int ts, sum;
	scanf("%d", &ts);
	while(ts--)
	{
		sum = 0;
		scanf("%s", num);
		reverse(num, num + strlen(num));
		for(int i = 0;num[i]; ++i)
			if(i%2)
				solve(i);
		for(int i = 0;num[i]; ++i)
			sum += num[i] - '0';
		printf("%s\n", sum % 10? "FAIL" : "PASS");
	}
	return 0;
}

