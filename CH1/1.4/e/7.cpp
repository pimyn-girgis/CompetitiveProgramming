#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    while(n--)
    {
    int x = 0, y = 0;
    bool found = 0;
    scanf("%d%d", &m, &x);
    for(int i = 2; i <= m; ++i)
    {
        scanf("%d", &y);
        if(y-x-1 && !found)
        {
            printf("%d\n", i);
            found = 1;
        }
        x = y;
    }
    }
    return 0;
}
