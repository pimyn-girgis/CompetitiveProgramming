#include <bits/stdc++.h>
using namespace std;
int s, rows, cols, i, j, k;
char n[15];

bool horizontal(bool up, bool mid, bool down)
{return k && k != cols -1 && (!i && up || i == rows/2 && mid || i == rows - 1 && down)? printf("-") : 0;}
bool vertical(bool topl, bool topr, bool botl, bool botr)
{
	return i && i != rows - 1
		&& (!k && (topl && i < rows/2 || botl && i > rows/2)
		  ||k == cols - 1 && (topr && i < rows/2 || botr && i > rows/2))?
		  printf("|") : 0;
}
bool output()
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
void solve()
{
	cols = s + 2;rows = 2 * s + 3;
	for(i=0;i<rows;++i, printf("\n"))
		for(j=0;n[j];n[++j]? printf(" ") : printf(""))
			for(k=0;k<cols;++k)
				if(output()) printf(" ");
	printf("\n");
}

int main()
{
	while (scanf("%d %s", &s, n) && s) solve();
	return 0;
}
