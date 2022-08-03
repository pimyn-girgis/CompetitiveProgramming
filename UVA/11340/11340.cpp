#include <bits/stdc++.h>
using namespace std;

int value[255];
#define MAX int(1e5 + 5)
char article[MAX];
unsigned long long int sum;


int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		memset(value, 0, sizeof(value));
		sum = 0;

		int k;
		scanf("%d", &k);

		char letter; int val;
		while (k--)
			scanf(" %c %d", &letter, &val), value[letter] = val;

		int m;
		scanf("%d ", &m);

		while(m--)
		{
			fgets(article, MAX, stdin);

			for(int i = 0; article[i]; ++i)
				sum += value[article[i]];
		}

		printf("%.2Lf$\n", static_cast<long double>(sum)/100);
	}
	return 0;
}
