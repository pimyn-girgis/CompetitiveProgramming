#include <bits/stdc++.h>
using namespace std;

vector <string> guest(1005);
int n;

void solve()
{
	string ans;
	string sml = guest[n/2-1];
	string big = guest[n/2];

	printf("%s\n", ans.c_str());
}

int main()
{
	char in[35];
	while(scanf("%d", &n) && n)
	{
		guest.resize(n);
		for(int i=0;i<n;++i) scanf("%s", in), guest[i] = in;
		sort(guest.begin(), guest.end());
		solve();
	}
	return 0;
}

/*
4 FRED SAM JOE MARGARET 2 FRED FREDDIE 2 JOSEPHINE JERRY 2 LARHONDA LARSEN 0
*/