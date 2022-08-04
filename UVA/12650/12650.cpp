#include <bits/stdc++.h>
using namespace std;

bool alive[int(1e4) + 5];

int main()
{
	int n, r;
	while(scanf("%d %d", &n, &r) != EOF)
	{
		memset(alive, 0, n * sizeof(bool));

		int val;
		for(int i = 0; i < r; ++i)
			scanf("%d", &val), alive[val - 1] = 1;

		bool found = 0;
		for(int i = 0; i < n; ++i)
			if(!alive[i]) printf("%d ", i + 1), found = 1;

		if(!found)
			printf("*");
		printf("\n");
	}
	return 0;
}
