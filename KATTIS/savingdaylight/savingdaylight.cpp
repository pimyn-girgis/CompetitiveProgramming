#include <bits/stdc++.h>
using namespace std;

int main() 
{
	char mon[20];
	int day, year, riseh, risem, seth, setm, hours, minutes;
	while(scanf("%s %d %d %d:%2d %d:%2d", mon, &day, &year, &riseh, &risem, &seth, &setm) != EOF)
	{
		hours = seth - riseh - (setm < risem);
		minutes = (setm-risem+60)%60;
		printf("%s %d %d %d hours %d minutes\n", mon, day, year, hours, minutes);
	}
	return 0;
}
