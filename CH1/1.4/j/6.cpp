#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts, sum, one, zero, mark;
	bool done;
	char S[105], T[105];

	scanf("%d", &ts);

	for(int a = 1; a <= ts; ++a)
	{
		sum = one = zero = mark = 0;

		scanf("%s%s", S, T);

		for(int i = 0; S[i]; ++i)
		{
			if(S[i] == '1')
				++one;
			if(T[i] == '1')
				--one;
		}

		if(one > 0)
		{
			printf("Case %d: -1\n", a);
			continue;
		}

		for(int i = 0; S[i]; ++i)
		{
			if(S[i] == '?')
			{
				++sum;

				if(one < 0)
				{
					S[i] = T[i];

					if(T[i] == '1')
						--one;
				}
				else
					S[i] = '0';
			}

		}
		for(int i = 0; S[i]; ++i)
		{
			done = 0;

			if(S[i] == T[i])
				continue;
			else
			{
				for(int j = i + 1; S[j]; ++j)
				{
					if(!done && T[i] == S[j] && T[j] != S[j] )
					{
						S[j] = T[j];
						++sum;
						done = 1;
					}
				}
			}
			if(!done)
				++sum;
		}

		printf("Case %d: %d\n",a, sum);
	}
	return 0;
}

