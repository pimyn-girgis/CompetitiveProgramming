#include <bits/stdc++.h>
using namespace std;

int main()
{
	char num[9] = "AKQJT987", suit[2], card[3];
	int domVal[8] = {11,4,3,20,10,14,0,0},
	    notVal[8] = {11,4,3,2,10,0,0,0}, n, sum = 0;

	scanf("%d%s", &n, suit);
	n*=4;
	while(n--)
	{
		scanf("%s", card);
		sum += card[1] == suit[0]? domVal[strchr(num, card[0])-num] : notVal[strchr(num, card[0])-num];
	}
	printf("%d", sum);
	return 0;
}

