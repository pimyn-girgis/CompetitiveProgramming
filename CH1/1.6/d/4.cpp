#include <bits/stdc++.h>
using namespace std;

char hand[5][5], num;
int val, maxVal, arr[13], temp[13], run[2], Begin[2], End[2];
char deck[52][3];

void fill()
{
}
int prize()
{
	if(run[0] == 5)	
		return 100;
	else if (run[0] == 4)
		return 10;
	else if(run[0] == 3 && run[1] == 2)
		return 5;
	else if(run[0] == 3)
		return 3;
	else if(run[0] == 2 && run[1] == 2)
		return 1;
	return 0;
}
void Run(int k)
{
	if(k == 2)
		return;
	val = maxVal = 0;
	for(int i = 0; i < 17; ++i)
		if(arr[i%13])
			++val;
		else 
		{
			if(val > maxVal)
			{
				maxVal = val;
				End[k] = i%13 - 1;	
				Begin[k] = (End[k] + 1 - maxVal + 13)%13;
			}
			val = 0;
		}
		run[k] = (maxVal);
		for(int i = Begin[k]; maxVal-- ;i = (i+1)%13)
			--arr[i];
	Run(++k);
}

void fix()
{
	for(int i = 0; i < 5; ++i)
	{
		num = hand[i][0];
		if(isdigit(num))
			++arr[num-'1'];
		else if(num == 'A')
			++arr[0];
		else if(num == 'T')
			++arr[9];
		else if(num == 'J')
			++arr[10];
		else if(num == 'Q') 
			++arr[11];
		else if(num == 'K')
			++arr[12];
	}
	copy(arr, arr+13, temp);
}

int main()
{
	while(scanf("%s", hand[0]) && hand[0][0] != '#')
	{
		memset(arr, 0, sizeof(arr));
		memset(run, 0, sizeof(run));
		for(int i = 1; i < 5; ++i)
			scanf("%s", hand[i]);
		fix();
		Run(0);
		if(run[0] == 5 || run[0] == 1)
			printf("Stay\n");
	}
	return 0;
}

