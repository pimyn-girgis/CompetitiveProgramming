#include <bits/stdc++.h>
using namespace std;

typedef vector <char> vc;
#define o(x) x == 1

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vc> island;
int a, b, c, d, n;
bool available(int x, int y){return isupper(island[x][y]);}
bool valid (int x, int y){return x < island.size() && y < island[0].size();}

void init()
{
	for(int i = min(b, d); i < island.size(); ++i)
		if(b > d) fill(island[i].begin() + a, island[i].end(), '.');
		else fill(island[i].begin(), island[i].begin() + a, '.');
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
	init();

	vector <int> part(n);
	for(auto &u : part) scanf("%d", &u);

	island = vector<vc>(max(b, d), vc(a + c, 'A'));

	int index = 0;
	for(int i = 0; i < island.size(); ++i)
		for(int j = 0; j < island[i].size(); ++j)
			if(available(i, j))
			{
				island[i][j] = index + 'a';
				if(!--part[index])
					++index;
			}

	for(auto &u : island)
	{
		for(auto &c : u)
			printf("%c", c);
		printf("\n");
	}

	return 0;
}

/*
	for(auto &u : island)
	{
		for(auto &c : u)
			printf("%c", c);
		printf("\n");
	}
*/