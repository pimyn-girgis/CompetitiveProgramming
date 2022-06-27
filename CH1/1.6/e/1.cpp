#include <bits/stdc++.h>
using namespace std;

char input[10005];
char keyboard[80] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
int length = strlen(keyboard);
char correct(char in){return *(find(keyboard, keyboard+length, in) - 1);}
int main()
{
	while(fgets(input, 10000, stdin))
	{
		int length = strlen(input) - 1;
		for(int i = 0; i < length; ++i)
			if(input[i] == ' ')
				printf(" ");
			else
				printf("%c", correct(input[i]));
		printf("\n");
	}
	return 0;
}

