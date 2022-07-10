#include <bits/stdc++.h>
using namespace std;

char in[100];
int Count = 16;
char pieces[8][8][5];
int white= 0, black = 0;
char val;

char symbol[5] = "KQRBN";

void print(bool whi, int x)
{
	if(x == 6)
		return;
	if(x == 5) val = 0;
	else val = symbol[x];

	for(int i = whi? 0 : 7; whi? i < 8 : i >= 0; i += whi? 1 : -1) 
		for(int j = 0; j < 8; ++j)
		{
			if(whi? isupper(pieces[i][j][0]) : islower(pieces[i][j][0]))
				if(toupper(pieces[i][j][0]) == val || val == 0 && toupper(pieces[i][j][0]) == 'P')
				{
					if(val) printf( "%c", val);
					printf( "%c%c", pieces[i][j][1], pieces[i][j][2]);
					if(whi && --white || !whi && --black)	printf( ",");
				}
		}
	print(whi, ++x);
}

void output()
{
	printf( "White: ");
	if(white)
		print(1, 0);
	printf( "\nBlack: ");
	if(black)
		print(0, 0);
	printf("\n");
}

int main()
{
	int index;
	int num = 17;
	memset(pieces, 0, sizeof(pieces));
	while(num--)
	{
		scanf("%s", in);
		if(!((--Count)%2))
		{
			index = 0;
			for(int i = 0; in[i]; ++i)
			{
				if(!((i-2)%4))
					if(in[i] != ':' && in[i] != '.')
					{
						isupper(in[i])? ++white : ++black;
						sprintf(pieces[Count/2][index++], "%c%c%c%c", in[i], 'a' + (i-2)/4 , '1' + Count/2, 0);
					}
			}
		}
	}
	output();
		return 0;
}
