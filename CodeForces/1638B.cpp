/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1638/B
* Insight : You cannot swap odd numbers with odd numbers or e-
            ven numbers with even numbers.
            so if you divide your array into two, odd and even
            if either is not sorted, you cannot sort it so you
            return false. If both are sorted then you can sort
            them if they are one array.
**************************************************************
*/

#include <cstdio>
#include <vector>
#include <algorithm>

//fancy way to write is_odd using & operator
#define is_odd(x) (x & 1)

bool solve()
{
    int n;
    scanf("%d", &n);

    std::vector<int> odd, even; odd.reserve(n); even.reserve(n); //reserve space in memory for later use

    int val;
    while(n--)
    {
        scanf("%d", &val);
        if(is_odd(val)) odd.push_back(val);
        else even.push_back(val);
    }

    return std::is_sorted(odd.begin(), odd.end()) && std::is_sorted(even.begin(), even.end());
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
        printf("%s\n", solve()? "YES" : "NO");

    return 0;
}
