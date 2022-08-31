/*
**************************************************************
* Author  : Bemen Girgis
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef long long unsigned int llu;
int len;
#define MAX 200000
char line[MAX];

int main()
{
	int left[MAX], right[MAX];

	int tc;
	scanf("%d", &tc);

	iota(left, left + MAX, 0);

	while(tc--)
	{
		scanf("%d %s", &len, line);

		reverse_copy(left, left + len, right);

		llu sum = 0;
		for(char *c = line; *c; ++c)
			sum += *c == 'L'? left[c - line] : right[c - line];

		string str(line);

		auto l = str.begin();
		auto r = str.rbegin();

		bool side = 0;

		for(int i = 0; i < len; ++i)
		{
			if(r.base() >= l)
			{
				l = find(l, str.end(), 'L');
				r = find(r, str.rend(), 'R');

				auto x = r - str.rbegin();
				auto y = l - str.begin();

				if(x < len && y < len)
				{
					if(left[x] >= right[y])
						str[x] = 'L', sum += (left[x] - right[x]), ++r;
					else 
						str[y] = 'R', sum += (right[y] - left[y]), ++l;
				}
			}

			printf("%llu ", sum);
		}
		printf("\n");
	}

	return 0;
}

