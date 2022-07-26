//https://open.kattis.com/problems/restaurant
#include <bits/stdc++.h>
using namespace std;

int pile1, pile2;

int main() 
{
	int n;
	scanf("%d", &n);
	while (n)
	{
		pile1 = pile2 = 0;
		char cmd[10];
		char mv;
		int plates;
		while(n--)
		{
			scanf("%s %d", cmd, &plates);
			mv = cmd[0];
			if(mv == 'T') //take
			{
				if(pile1 >= plates)
				{
					printf("TAKE 1 %d\n", plates);
					pile1 -= plates;
				}
				else if(!pile1)
				{
					printf("MOVE 2->1 %d\n", pile2);
					pile1 = pile2;
					pile2 = 0;
					printf("TAKE 1 %d\n", plates);
					pile1 -= plates;
				}
				else if(pile1 < plates)
				{
					printf("TAKE 1 %d\n", pile1);
					plates -= pile1;
					pile1 = 0;
					printf("MOVE 2->1 %d\n", pile2);
					pile1 = pile2; 
					pile2 = 0;
					printf("TAKE 1 %d\n", plates);
					pile1 -= plates;
				}
			}
			else //drop
			{
				printf("DROP 2 %d\n", plates);
				pile2 += plates;
			}
		}
		scanf("%d", &n);
		if(n) printf("\n");
	}
	return 0;
}
