#include <bits/stdc++.h>
using namespace std;

#define size 100005
int req[size];
void init(){memset(req, 0, sizeof(req));}
int main() 
{
    int n, k;
    init();
    scanf("%d %d", &n, &k);
    for(int i=0,val;i<n;++i)
    {
        scanf("%d", &val);
        for(int i=0;i<1000;++i)
            ++req[val+i];
    }
    printf("%d\n", int(ceil(*max_element(req, req+size)/double(k))));
    return 0;
}