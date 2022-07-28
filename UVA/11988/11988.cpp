#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e5 + 5)

list <char* > text;
char in[MAX];

int main()
{
	int len;
	while(scanf("%s%n", in, &len) != EOF)
	{
		text.clear();
		char *token = in;
		bool back = 1;
		for(int i = 0; i <= len; ++i)
		{
			if(in[i] == ']' || in[i] == '[' || !in[i])
			{
				if(back)
					text.push_back(token);
				else
					text.push_front(token);

				back = (in[i] == ']');
				in[i] = 0;
				token = in+i+1;
			}
		}
		for(auto &u : text)
			if(*u) printf("%s", u);
		printf("\n");
	}
	return 0;
}