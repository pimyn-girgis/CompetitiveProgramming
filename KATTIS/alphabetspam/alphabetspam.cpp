//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
using namespace std;

char email[int(1e5 + 5)];
int white = 0, lower = 0, upper = 0, symbols = 0;

int main() 
{
	scanf("%s", email);
	for(auto &u : email)
		if(!u) break;
		else if(u == '_') ++white;
		else if(islower(u)) ++lower;
		else if(isupper(u)) ++upper;
		else ++symbols;
	
	float sum = white + lower + upper + symbols;

	printf("%.7f\n%.7f\n%.7f\n%.7f\n", white/sum, lower/sum, upper/sum, symbols/sum);

	return 0;
}
