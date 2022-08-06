//https://open.kattis.com/problems/recount
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define MAX int(1e6 + 5)
char vote[MAX];

int main() 
{
	unordered_map <string, int> election;

	string winner;
	int maxVal = 0;
	bool runoff = 0;

	while (fgets(vote, MAX, stdin))
		if(maxVal < ++election[vote])
			maxVal = election[vote], winner = vote, runoff = 0;
		else if(maxVal == election[vote])
			runoff = 1;

	printf("%s", runoff? "Runoff!\n" : winner.c_str());
	return 0;
}
