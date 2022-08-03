#include <bits/stdc++.h>
using namespace std;

string value[6] = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"};
char in[25];

int main()
{
	while (scanf("%s", in) != EOF)
	{
		int code = 0;

		for(int i = 0; in[i]; ++i)
		{
			bool done = 0;
			char c = tolower(in[i]);

			for(int j = 0; j < 6 && !done; ++j)
			{	
				string &u = value[j];
				if(find(u.begin(), u.end(), c) != u.end())
				{
					done = 1;
					if(j + 1 != code)
						printf("%d", j + 1), code = j + 1;
				}
			}
			if(!done) code = 0;
		}
		printf("\n");
	}
	return 0;
}
