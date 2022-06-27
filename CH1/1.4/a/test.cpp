#include <bits/stdc++.h>
using namespace std;

int main()
{
int t, n, k, p, c = 0;
scanf("%d", &t);
while(t--)
        {
        c++;
        scanf("%d%d%d", &n, &k, &p);
	--k;
	p -= k;
	p %= n;
	++p;
        printf("Case: %d: %d\n",c, p);
        }
return 0;
}
