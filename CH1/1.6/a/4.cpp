#include <bits/stdc++.h>
using namespace std;

int prince[2]; //a, b
int sister[3]; //x, y, z
int ans, sum;
bool PrinceDone[2], SisterDone[3];

bool NotExist(int i)
{
				return find(sister, sister+3, i) == sister + 3 
					&& find(prince, prince+2, i) == prince + 2;
}

int FindAns(int least, int most)
{
	for(int i = least; i <= most; ++i)
			if(NotExist(i))
				return i;
	return -1;
}

int main()
{
	while(true)
	{
		sum = 0;
		ans =  -1;
		for(int i = 0; i < 3; ++i)
			scanf("%d", sister + i);
		for(int i = 0; i < 2; ++i)
			scanf("%d", prince + i);

		if(!sister[0])
			return 0;

		sort(sister, sister + 3);
		sort(prince, prince + 2);
		memset(PrinceDone, 0, 2);
		memset(SisterDone, 0, 3);
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 2; ++j)
				if(sister[i] > prince[j] && !PrinceDone[j] && !SisterDone[i])
				{
					PrinceDone[j] = true;
					SisterDone[i] = true;
					++sum;
				}
		if(!sum) ans = FindAns(1, 6);
		else if(sum == 1)
		{
			int cmp = prince[0];
			if(cmp < sister[1])
				ans = FindAns(sister[2], 52);
			else if(cmp < sister[2])
				ans = FindAns(sister[1], 52);
		}
		printf("%d\n", ans);
	}
}

