//https://open.kattis.com/problems/kattissquest
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);

    map <int, priority_queue<int>, greater<int> > query;

    while(n--)
    {
        char in[10];
        scanf("%s", in);

        if(in[0] == 'a')
        {
            int e, g;
            scanf("%d %d", &e, &g);
            query[e].push(g);
        }
        else
        {
            int x;
            scanf("%d", &x);

            long long unsigned int ans = 0;

			for(auto it = query.lower_bound(x); it != query.end() && x >= query.rbegin()->first; it = query.lower_bound(x))
			{
				label:
				while(it->second.size() && x >= it->first)
				{
					x -= it->first;
					ans += it->second.top();
					it->second.pop();

					if(it->second.empty())
					{
						if(it == query.begin())
						{
							it = query.erase(it);
							if(query.empty())
								goto out;
							goto label;
						}
						else
							it = --query.erase(it);
					}
				}
			}

			out:
            printf("%llu\n", ans);
        }
    }
    return 0;
}
