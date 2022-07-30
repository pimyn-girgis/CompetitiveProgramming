#include <bits/stdc++.h>
using namespace std;

int n, s, q, totalCargoes;

stack <int> cargo;
queue <int> platform[105];

int solve()
{
	int time = -2; //to accomodate for the first station

	for(int i = 0;totalCargoes;i = (i+1)%n)
	{
		time += 2;
		while(cargo.size())
		{
			if(cargo.top() == i + 1)
				cargo.pop(), --totalCargoes;
			else if(platform[i].size() < q)
			{
				platform[i].push(cargo.top());
				cargo.pop();
			}
			else
				break;
			++time;
		}
		while(cargo.size() < s && platform[i].size())
		{
			cargo.push(platform[i].front());
			platform[i].pop();
			++time;
		}
	}
	return time;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		totalCargoes = 0;
		scanf("%d %d %d", &n, &s, &q);
		for(int i = 0;i < n;++i)
		{
			int cargoes, val;
			scanf("%d", &cargoes);
			totalCargoes += cargoes;
			while(cargoes--)
				scanf("%d", &val), platform[i].push(val);
		}

		printf("%d\n", solve());
	}
	
	return 0;
}
