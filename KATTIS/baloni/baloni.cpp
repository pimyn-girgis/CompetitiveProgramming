#include <bits/stdc++.h>
using namespace std;

int arrow[1000005];

int main() 
{
	memset(arrow, 0, sizeof(arrow));
	int n, ans = 0;
    scanf("%d", &n);
    for(int i=0,k;i<n;++i)
	{
		scanf("%d", &k);
        if(arrow[k]) --arrow[k], ++arrow[k-1];
        else ++ans, ++arrow[k-1];
	}
    printf("%d\n", ans);
    return 0;
}