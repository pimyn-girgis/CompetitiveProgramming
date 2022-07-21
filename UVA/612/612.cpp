#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > val(105);
char str[105][55];

void solve()
{
	for(int i=0;i<val.size();++i)
		val[i] = {0, i};

	for(int i=0;i<val.size();++i)
		for(int j=0;str[i][j];++j)
			for(int k=j+1;str[i][k];++k)
				val[i].first += (str[i][k] < str[i][j]);

	stable_sort(val.begin(), val.end());
}

int main()
{
	int tc, len, num;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &len, &num);
		val.resize(num);
		for(int i=0;i<num;++i) scanf("%s", str[i]);
		solve();
		for(auto &u : val) printf("%s\n", str[u.second]);
		if(tc) printf("\n");
	}
	return 0;
}
