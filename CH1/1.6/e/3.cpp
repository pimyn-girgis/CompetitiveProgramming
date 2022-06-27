#include <bits/stdc++.h>
using namespace std;
float sum;

float mol[128]; 
void add(char atom, int num){sum += num * mol[atom];}
int main()
{
	mol['C'] = 12.01, mol['H'] = 1.008, mol['O'] = 16, mol['N'] = 14.01;
	int t;
	char formula[100], copy[100];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", formula);
		strcpy(copy, formula);
		sum = 0;
		char *token = strtok(formula, "CHON");
		for(int i = 0; i < copy[i]; ++i)
		{
			if(isalpha(copy[i]) && isdigit(copy[i+1]))
			{
				if(token)add(copy[i], atoi(token));
				else add(copy[i], 1);
				token = strtok(nullptr, "CHON");
			}
			else if(isalpha(copy[i])) add(copy[i], 1);
		}
		printf("%.3f\n", sum);
	}
	return 0;
}

