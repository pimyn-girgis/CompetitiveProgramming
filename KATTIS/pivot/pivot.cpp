//  #include <bits/stdc++.h>
//  using namespace std;

// int arr[100005];
// int maxBefore[100005];
// int minAfter[100005];
// int n;

// void init()
// {
//     memset(maxBefore, 0, sizeof(maxBefore));
//     memset(minAfter, 0, sizeof(minAfter));
//     maxBefore[0] = INT_MIN;
//     minAfter[n-1] = INT_MAX;
// }

// void solve()
// {
//     int val = 0;
//     for(int i=1;i<n;++i)
//         maxBefore[i] = max(maxBefore[i-1], arr[i-1]);
//     for(int i=n-2;i>=0;--i)
//         minAfter[i] = min(minAfter[i+1], arr[i+1]);
//     for(int i=0;i<n;++i)
//         val += (arr[i] >= maxBefore[i] && arr[i] < minAfter[i]);
//     printf("%d\n", val);
// }

// int main() 
// {
//     scanf("%d", &n);
//     init();
//     for(int i=0;i<n;++i)
//         scanf("%d", arr+i);
//     solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int ans = 0;

    scanf("%d",&n);
    long long int arr[n];
    long long int minVal = LONG_MAX, maxVal = LONG_MIN;

    map <long long int,bool> minMap, maxMap;

    for(int i = 0;i < n;++i) scanf("%lld",arr + i);

    for(int i = 0;i < n;++i)
        if(arr[i] > maxVal)
            maxMap[arr[i]] = 1, maxVal = arr[i];

    for(int i = n-1;i >= 0;i--)
        if(arr[i] < minVal)
            minMap[arr[i]] = 1, minVal = arr[i];

    for(auto &u:minMap)
        ans += (u.second && maxMap[u.first]);

    printf("%d\n", ans);
    return 0;
}