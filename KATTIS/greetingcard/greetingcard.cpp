//https://open.kattis.com/problems/greetingcard
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
set <pii> point;
set <pii> diff;

int first_sign[] = {1, 1, -1, -1};
int second_sign[] = {1, -1, 1, -1};

void init()
{
	for(int i = 0; i <= 2018;++i)
		for(int j = 2018; j >= 0; --j)
			if((i * i + j * j) == 4072324)
			{
				diff.insert(pii(i, j));
				break;
			}
}

int main() 
{
	init();
	int n;
	scanf("%d", &n);

	pair <int, int> cur;
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &cur.first, &cur.second), point.insert(cur);

	int ans = 0;
	while(!point.empty())
	{
		auto &p1 = *point.begin();
		auto x = p1.first;
		auto y = p1.second;

		for(auto &u : diff)
		{
			bool zero = 1;
			for(int i = 0; i < 4; ++i)
			{
				if(point.find(pii(x + first_sign[i] * u.first, y + second_sign[i] * u.second)) != point.end())
					ans += zero;
				if(u.first == 0 || u.second == 0)
					zero = 0;
			}
		}

		point.erase(point.begin());
	}
		
	printf("%d\n", ans);
	return 0;
}
