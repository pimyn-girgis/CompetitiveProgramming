#include <bits/stdc++.h>
using namespace std;

bool solved[105][15];
bitset<15> done;
int lastTime[15];
int lastID[15];

int main()
{
	int n, t, m, time, id, prob;
	char in[5];
	scanf("%d %d %d", &n, &t, &m);
	for(int i=0;i<m;++i)
	{
		scanf("%d %d %d %s", &time, &id, &prob, in);
		prob -= 'A';
		if(in[0] == 'Y' && !solved[id][prob])
			solved[id][prob] = 1, lastID[prob] = id, lastTime[prob] = time, done[prob] = 1;
	}
	for(int i=0;i<n;++i)
		if(done[i]) printf("%c %d %d\n", i + 'A', lastTime[i], lastID[i]);
		else printf("%c - -", i + 'A');
	return 0;
}
