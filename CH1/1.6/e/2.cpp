#include<cstdio>
using namespace std;

int main()
{
	int pages, blanks, stack[50][2], sheets; //stack[sheet-num][front-back][first-second]
	while(scanf("%d", &pages) && pages)
	{
		blanks = (4 - pages%4)%4;
		sheets = pages/4 + bool(pages%4);
		int m = 1, n = 4 * sheets;
		bool k = 0;
		for(int i = 0; i < 2 * sheets; ++i)
		{
			stack[i][k] = n--;
			stack[i][!k] = m++;
			k = !k;
		}
		int total = pages;
		int count = 1;
		bool front = 1;
		printf("Printing order for %d pages:\n", pages);
		for(int i = 0;total> 0; ++i)
		{
			printf("Sheet %d, %s ", count, front? "front:" : "back :");
			for(int j = 0; j < 2; ++j)
			{
				//printf("%s ", front? "front:" : "back :");
				if(stack[i][j] <= pages){printf("%d", stack[i][j]); --total;}
				else printf("Blank");
				if(!j) printf(", ");
			}
			front = !front;
			count += front;
			printf("\n");
		}
	}
	return 0;
}