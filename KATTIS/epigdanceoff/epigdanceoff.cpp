#include <bits/stdc++.h>
using namespace std;

char Move[2005][2005];

int main() 
{
    int n, m, ans=1;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i)
        scanf("%s", Move[i]);

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
            if(Move[j][i] == '$')
                goto label;
        ++ans;
        label:
        continue;
    }
    printf("%d\n", ans);
    return 0;
}
