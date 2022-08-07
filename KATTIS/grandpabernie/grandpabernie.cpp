//https://open.kattis.com/problems/grandpabernie
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);

	unordered_map <string, vector <int> > travelHistory;
	char country[25];
	int year;

	while(n--)
		scanf("%s %d", country, &year), travelHistory[country].push_back(year);

	for(auto &u : travelHistory)
		sort(u.second.begin(), u.second.end());

	int q;
	scanf("%d", &q);

	int k;
	while(q--)
		scanf("%s %d", country, &k), printf("%d\n", travelHistory[country][k-1]);

	return 0;
}
