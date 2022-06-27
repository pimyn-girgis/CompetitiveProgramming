#include <bits/stdc++.h>
using namespace std;

int Time[100], zero, minVal, interval, 
	length, ans, Begin, hour, minute, second;
bool green[18000];
bool over = 0;

bool input()
{
	memset(Time, 0, sizeof(Time));
	memset(green, 1, sizeof(green));
	ans = 0;
	for(int i = 0;;++i)
	{
		scanf("%d", Time + i);
		if(!Time[i] && !i)
			over = 1;
		if(!Time[i])
			break;
	}
	if(over)
	{
		scanf("%d %d", &zero, &zero);
		return 1;
	}
	return 0;
}

void solve()
{
	minVal = 1e9;
	for(int i = 0; Time[i]; ++i)
	{
		minVal = min(minVal, Time[i]);
		interval = 2 * Time[i]; //Time between two orange cells 
		length = Time[i] + 5; //red or orange
		Begin = Time[i] - 6;
		for(int j = 0; Begin + j * interval < 18000; ++j)
			memset(green + Begin + j * interval, 0, min(length, 18000 - (Begin + j * interval)));
	}
	memset(green, 0, minVal);
	for(int i = 0; i < 18000; ++i)
		if(green[i])
			{
				ans = i + 1;
				return;
			}
}
int main()
{
	while(!over)
	{
		if(input()) return 0;
		solve();
		if(ans)
		{
			hour = ans / 3600;
			ans %= 3600;
			minute = ans / 60;
			ans %= 60;
			second = ans;
			printf("%.2d:%.2d:%.2d\n", hour, minute, second);
		}
		else
			printf("Signals fail to synchronise in 5 hours\n");
	}
}