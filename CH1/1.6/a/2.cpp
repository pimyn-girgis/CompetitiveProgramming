#include <bits/stdc++.h>
using namespace std;

int main()
{
	char johnHand[105], janeHand[105], johnPile[105], janePile[105];
	int turn,ts, johnHandTop, janeHandTop, johnPileTop, janePileTop;
	bool johnWin, janeWin;
	scanf("%d", &ts);
	while(ts--)
	{
		memset(johnHand, 0, 105);
		memset(johnPile, 0, 105);
		memset(janeHand, 0, 105);
		memset(janeHand, 0, 105);
		scanf("%s%s", janeHand, johnHand);
		johnHandTop = janeHandTop = strlen(johnHand)-1;
		johnPileTop = janePileTop = -1;
		turn = janeWin = johnWin = 0;
		reverse(johnHand, johnHand + johnHandTop + 1);
		reverse(janeHand, janeHand + janeHandTop + 1);
		while(turn < 1000 && !johnWin && !janeWin)
		{
			if(johnHandTop > -1)
			johnPile[++johnPileTop] = johnHand[johnHandTop--];
			if(janeHandTop > -1)
			janePile[++janePileTop] = janeHand[janeHandTop--];
			++turn;
			if(johnPile[johnPileTop] == janePile[janePileTop])
			{
				if(random()/141%2)
				{
					for(int j = 0; janePileTop-j > -1; ++j)
						johnPile[++johnPileTop] = janePile[j];
					janePileTop = -1;
					printf("Snap! for John: ");
					for(int j = johnPileTop; j >= 0; --j)
						printf("%c", johnPile[j]);
					printf("\n");
				}
				else
				{
					for(int j = 0; johnPileTop-j > -1; ++j)
						janePile[++janePileTop] = johnPile[j];
					johnPileTop = -1;
					printf("Snap! for Jane: ");
					for(int j = janePileTop; j >= 0; --j)
						printf("%c", janePile[j]);
					printf("\n");
				}
			}

			if(janeHandTop == janePileTop && janeHandTop == -1)
				johnWin = 1;

			if(johnHandTop == johnPileTop && johnHandTop == -1)
				janeWin = 1;

			if(janeHandTop == -1)
				while(janePileTop>-1)
					janeHand[++janeHandTop] = janePile[janePileTop--];
			
			if(johnHandTop == -1)
				while(johnPileTop>-1)
					johnHand[++johnHandTop] = johnPile[johnPileTop--];

		}
		if(turn == 1000)
			printf("Keeps going and going ...\n");
		else
			printf("%s wins.\n", johnWin? "John" : "Jane");
		if(ts)
			printf("\n");
	}
	return 0;
}
