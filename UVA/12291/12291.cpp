#include <bits/stdc++.h>
using namespace std;

vector < bitset<11> > large(11, bitset<11> (0));
vector < bitset<11> > small(11, bitset<11> (0));
vector < bitset<11> > done(11, bitset<11> (0));
int n, m;

bool isValid(int x){return x < 10 && x >= 0;}
bool isValid(int x, int y){return isValid(x) && isValid(y);}

void input()
{
	char in[15];
	for(int i=0;i<n;++i)
	{
		scanf("%s", in);
		for(int j=0;in[j];++j)
			large[i][j] = in[j] == '*';
	}

	for(int i=0;i<m;++i)
	{
		scanf("%s", in);
		for(int j=0;in[j];++j)
			small[i][j] = in[j] == '*';
	}
}

void init()
{
	for(auto &u : large) u.reset();
	for(auto &u : small) u.reset();
	for(auto &u : done) u.reset();
}

bool solve()
{
	return 0;
}

int main()
{
	while(scanf("%d %d", &n, &m) && n && m)
	{
		init();
		input();
		printf("%d\n", solve());
	}
	return 0;
}
