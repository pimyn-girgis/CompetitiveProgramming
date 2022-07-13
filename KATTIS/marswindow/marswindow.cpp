#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int y;
	int mon = 4, year = 2018;
	scanf("%d", &y);
	while(year < y)
	{
		mon += 2;
		year += 2 + mon/13;
		mon %= 12;
		if(!mon) mon = 12;
	}
	printf("%s\n", y==year? "yes" : "no");
	return 0;
}
