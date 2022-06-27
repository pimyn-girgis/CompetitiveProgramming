#include <bits/stdc++.h>
using namespace std;

int conWin, Rank, Count, req;// bonus Rank 6 -> 25 and 3 con wins.
char input[10005];
bool win;

bool bonus(){return conWin >= 3 && 6 <= Rank && Rank <= 25;}
bool lose(){return 1 <= Rank && Rank <= 20;}
bool drop(){return 1 <= Rank && Rank < 20;}
void stars(){Count += win? 1 + bonus() : -lose();}
void reqStars()
{
		 if(Rank > 20) req = 2;
	else if(Rank > 15) req = 3;
	else if(Rank > 10) req = 4;
	else if(Rank >  0) req = 5;
}
void fix()
{
	if(!Rank)
		return;
	stars();
	reqStars();
	if(Count > req)
	{
		--Rank;
		Count -= req;
	}
	else if(Count < 0 && drop())
	{
		++Rank;
		reqStars();
		Count += req;
	}
	if(Count < 0) Count = 0;
}
int main()
{
	scanf("%s", input);
	Count = conWin = 0;
	Rank = 25;
	for(int i = 0; input[i]; ++i)
	{
		if(input[i] == 'W')
			win = 1, ++conWin;
		else
			win = 0, conWin = 0;
		fix();
	}
	Rank? printf("%d", Rank) : printf("Legend");
}

