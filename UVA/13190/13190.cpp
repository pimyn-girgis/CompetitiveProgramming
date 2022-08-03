#include <bits/stdc++.h>
using namespace std;

#define si pair<string, int> 
#define iis tuple<int, int, string> 
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
			scanf("%s %d", in, &val), freq[in] = val, pq.push(iis(val, i, in));

		int t = 0;
		iis med(0, 0, " ");

		while(k--)
		{
			int val = get<0>(med);
			med = pq.top(); pq.pop();

			//auto [f, s, i] = med; C++ 17 doesn't work with UVA but allowed in ICPC

			int f = get<0>(med);
			string s = get<2>(med);
			int i = get<1>(med);

			t += abs(f - val);

			printf("%d %s\n", t, s.c_str());

			pq.push(iis(f + freq[s], i , s));
		}
	}
	return 0;
}
