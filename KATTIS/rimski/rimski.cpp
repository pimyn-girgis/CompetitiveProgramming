#include <bits/stdc++.h>
using namespace std;

char tens[10][10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char ones[10][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char numbers[100][15];
char roman[15];
char ans[15];
int len;

void preprocess()
{
	int k = 0;
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j, ++k)
			sprintf(numbers[k], "%s%s", tens[i], ones[j]);
}

int translate()
{
	for(int i=0;i<100;++i)
		if(!strcmp(numbers[i], roman))
			return i;
	return INT_MAX;
}

int main() 
{
	preprocess();
	int val = INT_MAX;
	scanf("%s%n", roman, &len);
	sort(roman, roman+len);
	do
	{
		int comp = translate();
		if(val > comp)
		{
			strcpy(ans, roman);
			val = comp;
		}
	} while (next_permutation(roman, roman+len));
	printf("%s\n", ans);
	return 0;
}
