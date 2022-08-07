//https://open.kattis.com/problems/competitivearcadebasketball
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() 
{
	int n, p, m;
	scanf("%d %d %d", &n, &p, &m);

	while(n--)
		scanf("%*s");

	char name[25];
	int points;
	unordered_map<string, int> score;
	unordered_set <string> winnerList;
	queue <string> outList;

	while (m--)
	{
		scanf("%s %d", name, &points);
		score[name] += points;

		if(score[name] >= p)
			if(winnerList.insert(name).second)
				outList.push(name);
	}

	while(outList.size())
			printf("%s wins!\n", outList.front().c_str()), outList.pop();

	if(winnerList.empty()) printf("No winner!\n");
	
	return 0;
}
