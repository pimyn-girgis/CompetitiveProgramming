#include <bits/stdc++.h>
using namespace std;

vector <stack<char> > ship;
int len;
char cont[1005];

int solve()
{
	ship.clear();
	for(int i = 0;i < len;++i)
	{
		bool found = 0;
		for(int j = 0;!found && j < ship.size();++j)
			for(int k = 0;cont[i] + k <= 'Z'; ++k)
				if(ship[j].top() == cont[i]+k)
				{
					ship[j].push(cont[i]);
					found = true;
				}
		if(!found) ship.push_back(stack<char>()), ship.back().push(cont[i]);
	}
	return ship.size();
}

int main()
{
	int caseNo = 0;
	while (scanf("%s%n", cont, &len), strcmp(cont, "end"))
		printf("Case %d: %d\n", ++caseNo, solve());
	
	return 0;
}
