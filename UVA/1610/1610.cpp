#include <bits/stdc++.h>
using namespace std;

vector <string> guest(1005);
int n;

string solve()
{
	string ans(40, ' ');
	string sml = guest[n/2-1];
	string big = guest[n/2];
	int k = 0;
	while(ans < sml || ans >= big)
	{
		bool done = 0;
		ans.resize(k+1);

		char fir = k < sml.size()? sml[k] : 'A';
		char sec = k < big.size()? big[k] : 'Z';

		for(char i = fir;i <= sec;++i)
		{
			ans[k] = i;
			if(ans < big && ans >= sml)
				return ans;
		}
		ans[k] = fir;
		++k;
	}
	return ans;
}

int main()
	{
	char in[35];
	while(scanf("%d", &n) && n)
	{
		guest.resize(n);
		for(int i=0;i<n;++i) scanf("%s", in), guest[i] = in;
		sort(guest.begin(), guest.end());
		printf("%s\n", solve().c_str());
	}
	return 0;
}

/*
4 FRED SAM JOE MARGARET 2 FRED FREDDIE 2 JOSEPHINE JERRY 2 LARHONDA LARSEN 0
*/