#include <bits/stdc++.h>
using namespace std;

int main()
{
	char x[20];
	int i = 1;
	while(scanf("%s", x))
	{
		if(!strcmp("#", x))
			break;
		printf("Case %d: ", i);
		++i;
		if(!strcmp("HELLO", x))
			printf("ENGLISH");
		else if(!strcmp("HOLA", x))
			printf("SPANISH");
		else if(!strcmp("HALLO", x))
			printf("GERMAN");
		else if(!strcmp("BONJOUR", x))
			printf("FRENCH");
		else if(!strcmp("CIAO", x))
			printf("ITALIAN");
		else if(!strcmp("ZDRAVSTVUJTE", x))
			printf("RUSSIAN");
		else
			printf("UNKNOWN");
		printf("\n");
	}
	return 0;
}

