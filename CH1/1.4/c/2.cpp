#include <bits/stdc++.h>
using namespace std;

int main()
{
	char x[7];
	scanf("%[^\n]s", x);
	if(!strcmp(x, "OCT 31") || !strcmp(x, "DEC 25"))
		printf("yup");
	else
		printf("nope");
	return 0;
}

