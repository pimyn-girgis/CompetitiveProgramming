#include <bits/stdc++.h>
using namespace std;

unordered_map <int, bitset<3> > chocolate;

void input(int x, int pos)
{
	int val;
	while(x--) scanf("%d", &val), chocolate[val].set(pos);
}

void input(int l, int r, int s)
{
	input(l, 0), input(r, 1), input(s, 2);
}

void solve(int tc)
{
	int only[3] = {0};
	int both[3] = {0};

	for(auto &u : chocolate)
	{
		auto &v = u.second;

		if(v.count() == 1)
			for(int i = 0; i < 3; ++i)
				only[i] += bool(v[i]);

		else if(v.count() == 2)
			for(int i = 0; i < 3; ++i)
				both[i] += bool(!v[i]);
	}

	printf("Case #%d:\n", tc);

	for(int i = 0; i < 3; ++i)
		printf("%d %d\n", only[i], both[i]);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	chocolate.reserve(int(1e6));

	for(int caseNo = 1; caseNo <= tc; ++caseNo)
	{
		chocolate.clear();

		int l, r, s;
		scanf("%d %d %d", &l, &r, &s);
		input(l, r, s);

		solve(caseNo);
	}

	return 0;
}