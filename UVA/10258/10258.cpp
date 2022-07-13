#include <bits/stdc++.h>
using namespace std;

#define rank tuple<int, int, int> //solved, penalty, number

vector <rank> board(105);

bool comp(rank fir, rank sec)
{
	auto &sol1 = get<0>(fir), &pen1 = get<1>(fir), &num1 = get<2>(fir);
	auto &sol2 = get<0>(sec), &pen2 = get<1>(sec), &num2 = get<2>(sec);

	if(sol1 != sol2)
		return sol1 > sol2;
	else if(pen1 != pen2)
		return pen1 < pen2;
	else
		return num1 < num2;
}

void enter(int num, int prob, int tim, char judge)
{
	board[num];
	auto &sol1 = get<0>(fir), &pen1 = get<1>(fir), &num1 = get<2>(fir);
	auto &sol2 = get<0>(sec), &pen2 = get<1>(sec), &num2 = get<2>(sec);
}

int main()
{
	int ts;
	char in[105];
	int time, prob, num;
	char judge;

	scanf("%d", &ts);
	while(ts--)
	{
		fgets(in, 100, stdin);
		if(!strcmp(in, "\n")) solve();
		else
		{
			sscanf(in, "%d %d %d %c", &num, &prob, &tim, &judge);
			enter(num, prob, tim, judge);
		}
	}
	return 0;
}
