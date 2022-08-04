#include <bits/stdc++.h>
using namespace std;

short int freq[1005][26];
char dna[51][1005];

int main()
{
	int tc;
	scanf("%d", &tc);
	
	int m, n;
	char c;

	while(tc--)
	{
		memset(freq, 0, sizeof(freq));

		scanf("%d %d\n", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%s", dna[i]);

		for(int i = 0;i < m; ++i)
			for(int j = 0; j < n; ++j)
				++freq[j][dna[i][j] - 'A'];

		int err = 0;

		for(int i = 0; i < n; ++i)
		{
			char ans = max_element(freq[i], freq[i] + 26) - freq[i] + 'A';

			for(int j = 0; j < m; ++j)
				err += (dna[j][i] != ans);

			printf("%c", ans);
		}

		printf("\n%d\n", err);
	}
	return 0;
}
