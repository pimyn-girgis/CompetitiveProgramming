#include <bits/stdc++.h>
using namespace std;

#define si pair<string, int> 
#define iis pair<int, pair<int, string> > 
#define is pair<int, string> 

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		int n, k;
			scanf("%d %d", &n, &k);
		
		priority_queue <iis, vector<iis>, greater<iis> > pq;
		unordered_map <string, int> freq;

		char in[20];
		int val;

		for(int i = 0; i < n; ++i)
			scanf("%s %d", in, &val), freq[in] = val, pq.push(iis(val, make_pair(i, in)));

		int t = 0;
		iis med(0, make_pair(0, " "));

		while(k--)
		{
			int val = med.first;
			med = pq.top(); pq.pop();

			int f = med.first;
			string s = med.second.second;
			int i = med.second.first;

			t += abs(f - val);

			printf("%d %s\n", t, s.c_str());

			pq.push(iis(f + freq[s], is(i , s)));
		}
	}
	return 0;
}
