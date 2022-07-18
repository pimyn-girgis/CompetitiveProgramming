#include <bits/stdc++.h>
using namespace std;

int score[105];
int pen[105];
int potPen[105][9];
bool solved[105][9];
bool sub[105];
char in[100];
int Time, con, prob;
char judge;
int leader[105];

void init()
{
	memset(score, 0, sizeof(score));
	memset(solved, 0, sizeof(solved));
	memset(pen, 0, sizeof(pen));
	memset(potPen, 0, sizeof(potPen));
	memset(sub, 0, sizeof(sub));
	for(int i=0;i<105;++i) leader[i] = i;
}

bool comp(int x, int y)
{
	if(score[x] != score[y])
		return score[x] > score[y];
	if(pen[x] != pen[y])
		return pen[x] < pen[y];
	return x < y;
}

int main()
{
	int ts;
	scanf("%d", &ts);
	fgets(in, 100, stdin);
	while (ts--)
	{
		init();
		while(1)
		{
			if(!fgets(in, 100, stdin) || in[0] == '\n') break;

			sscanf(in, "%d %d %d %c", &con, &prob, &Time, &judge);
			--con, --prob;
			sub[con] = 1;

			if(!solved[con][prob])
			{
				if(judge == 'I') potPen[con][prob] += 20;
				else if(judge == 'C')
				{
					solved[con][prob] = 1;
					pen[con] += potPen[con][prob] + Time;
					++score[con];
				}
			}
		}
		stable_sort(leader, leader+105, comp);
		for(int i=0;i<105;++i)
		{
			int index = leader[i];
			if(sub[index]) printf("%d %d %d\n", index+1, score[index], pen[index]);
		}
		if(ts) printf("\n");
	}
}
