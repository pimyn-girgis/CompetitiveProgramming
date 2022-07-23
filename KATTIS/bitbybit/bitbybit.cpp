//https://open.kattis.com/problems/bitbybit
#include <bits/stdc++.h>
using namespace std;

char cmd[10];
char out[33];

int main() 
{
	int n;
	int bit1, bit2;
	out[32] = 0;
	while(scanf("%d", &n), n)
	{
		memset(out, '?', 32);
		while(n--)
		{
			scanf("%s %d", cmd, &bit1);
			char mv = cmd[0];
			if(mv == 'A' || mv == 'O') scanf("%d", &bit2);

			if(mv == 'S') out[bit1] = '1';
			else if(mv == 'C') out[bit1] = '0';
			else if(mv == 'O')
			{
 				if(out[bit2] == '1') out[bit1] = '1';
				else if(out[bit2] == '?' && out[bit1] == '0') out[bit1] = '?';
			}
			else if(mv == 'A')
			{
				if(out[bit2] == '0') out[bit1] = '0';
				else if(out[bit2] == '?' && out[bit1] != '0') out[bit1] = '?';
			}
		}
		reverse(out, out+32);
		printf("%s\n", out);
	}
	return 0;
}