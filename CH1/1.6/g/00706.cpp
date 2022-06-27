#include <bits/stdc++.h>
using namespace std;
FILE *out = fopen("out", "a");
int s, rows, cols, i, j, k;
char n[15];

inline bool horizontal(bool up, bool mid, bool down)
{
	if(k && k != cols -1 && (!i && up || i == rows/2 && mid || i == rows - 1 && down))
	{
		printf("-");
		return 1;
	}
	return 0;
}
inline bool vertical(bool topl, bool topr, bool botl, bool botr)
{
	bool val = 0;
	if(i && i != rows - 1
	&& (!k && (topl && i < rows/2 || botl && i > rows/2)
	|| k == cols - 1 && (topr && i < rows/2 || botr && i > rows/2)))
	{
		printf("|");
		val = 1;
	}
	return val;
}
inline bool output()
{
				char v = n[j];
				return
				 ((v == '0' && !vertical(1,1,1,1) && !horizontal(1,0,1))
				||(v == '1' && !vertical(0,1,0,1) && !horizontal(0,0,0))
				||(v == '2' && !vertical(0,1,1,0) && !horizontal(1,1,1))
				||(v == '3' && !vertical(0,1,0,1) && !horizontal(1,1,1))
				||(v == '4' && !vertical(1,1,0,1) && !horizontal(0,1,0))
				||(v == '5' && !vertical(1,0,0,1) && !horizontal(1,1,1))
				||(v == '6' && !vertical(1,0,1,1) && !horizontal(1,1,1))
				||(v == '7' && !vertical(0,1,0,1) && !horizontal(1,0,0))
				||(v == '8' && !vertical(1,1,1,1) && !horizontal(1,1,1))
				||(v == '9' && !vertical(1,1,0,1) && !horizontal(1,1,1)));
}
inline void solve()
{
	cols = s + 2;rows = 2 * s + 3;
	for(i=0;i<rows;++i)
	{
		for(j=0;n[j];++j)
		{
			for(k=0;k<cols;++k)
			{
				if(output()) printf(" ");
			}
			if(n[j+1]) printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	while (scanf("%d %s", &s, n) && s)
		solve();
	return 0;
}