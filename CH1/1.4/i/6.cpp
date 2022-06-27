#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	bool pea, pan, done;
	char str[105], name[105];
	scanf("%d", &n);
	done = 0;
	while(n--)
	{
		pea = pan = 0;
		scanf("%d", &k);
		while(getchar() != '\n');
		fgets(name, 105, stdin);
		while(k--)
		{
			fgets(str, 105, stdin);
			pea |= !strcmp(str, "pea soup\n");
			pan |= !strcmp(str, "pancakes\n");
			if(!done && pan && pea)
			{
				printf("%s", name);
				done = 1;
			}
		}
	}
	if(!done)
		printf("Anywhere is fine I guess");
	return 0;
}

