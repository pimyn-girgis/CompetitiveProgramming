#include <bits/stdc++.h>
using namespace std;

int ans[1000005];
int main() 
{
    int k, n, val = 0;
    scanf("%d", &n);
    for(int i=0, prev = 0;i<n;++i)
    {
        scanf("%d", &k);
        if(k > prev) ans[val++] = prev = k;
    }
    printf("%d\n", val);
    for(int i=0;i<val;++i) printf("%s%d", i? " " : "", ans[i]);
    printf("\n");
    return 0;
}
