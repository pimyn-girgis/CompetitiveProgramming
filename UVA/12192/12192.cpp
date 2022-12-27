/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12192 UVA
* Link    : https://onlinejudge.org/external/121/p12192.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    int n, m;
    int height[505][505];

    while(scanf("%d %d\n", &n, &m), n && m)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d%*c", height[i] + j);
        
        int q; scanf("%d\n", &q);
        while(q--)
        {
            int min_val, max_val; scanf("%d %d\n", &min_val, &max_val);
        }
    }

    return 0;
}
