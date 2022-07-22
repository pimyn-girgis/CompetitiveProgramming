#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() 
{
    int tc;
    long long unsigned int v;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d %d %d %d %d", &n, &a, &b, &c, &x, &y);

		int val = a;
        for(int i=1;i<n;++i) seq[i] = (seq[i-1]*b+a)%c;

        v = 0;
        for(int i=0;i<n;++i) v = (v * x + seq[i]) % y;
        printf("%llu\n", v);
    }
    return 0;
}