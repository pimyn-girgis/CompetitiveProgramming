#include <bits/stdc++.h>
using namespace std;

int d1, m1, year1, c1, d2, m2, year2, c2;
bool bigMon[12] = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};

bool isLeap(int year){return !(year%4) && year%100 || !(year%400);}

bool consecutive()
{
	return (d1 == d2-1 && m1 == m2 && year1 == year2)
		|| (d1 == 30 + bigMon[m1-1] && d2 == 1 && m1 == m2-1 && year2 == year1)
		|| (d1 == 28 + isLeap(year1) && d2 == 1 && m1 == 2 && m2 == 3 && year1 == year2)
		|| (d1 == 31 && d2 == 1 && m1 == 12 && m2 == 1 && year1 == year2-1);
}

int main()
{
	int n;
	int days, sum;
	while(scanf("%d", &n) && n)
	{
		days = sum = 0;
		for(int i=0;i<n;++i)
		{
			if(i)
			{
				d1 = d2, m1 = m2, c1 = c2, year1 = year2;
				scanf("%d %d %d %d", &d2, &m2, &year2, &c2);
				if(consecutive())
				{
					//printf("%d\n", d1);
					sum += (c2-c1);
					++days;
				}
			}
			else
				scanf("%d %d %d %d", &d2, &m2, &year2, &c2);
		}
		printf("%d %d\n", days, sum);
	}
	return 0;
}
