/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1618/D
* Insight : It's trivial to see that we want to get rid of the
            greatest k elements. Accordingly, they will always
            be our denominators. Now, how would we choose the 
            k numerators. If we pick the k greatest elements
            as denominators, every fraction will be either ev-
            aluate to 1 or 0.
            You might be intrigured to minimize the values of
            the fractions by trying to zero most of them, but
            notice that by doing that you only decrease their
            values from 1 to 0, and you increase the potential
            values of the remaining elements by at least 1.
**************************************************************
*/

#include <cstdio>
#include <vector>
#include <algorithm>

int solve()
{
    int n, k, score = 0;
    scanf("%d %d", &n, &k);

    std::vector<int> arr(n);
    for(auto &u : arr) scanf("%d", &u);

    std::sort(arr.rbegin(), arr.rend());

    for(int i = 0, j = k; j < 2 * k; ++i, ++j)
        score += arr[j]/arr[i];
    
    for(int i = 2 * k; i < n; ++i)
        score += arr[i];

    return score;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
        printf("%d\n", solve());

    return 0;
}
