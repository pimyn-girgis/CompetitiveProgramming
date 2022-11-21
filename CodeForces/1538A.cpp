/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1538/A
* Insight : get the indices of the max and min elements. comp-
            re all possible choices:
                                    1 - break from both ways
                                    2 - break from left only
                                    3 - break from right only
            Choose the one requiring the least number of oper-
            ations
**************************************************************
*/

#include <cstdio>
#include <utility>

#define min(x, y) (x < y? x : y)

int min_val(int x, int y, int z) { return min(min(x, y), z); }

typedef std::pair<int, int> pii;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

pii min_max(int n)
{
    int max_val = -1e9, max_index = 0, min_val = 1e9, min_index = 0, val;

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &val);
        if(max_val < val) max_val = val, max_index = i;
        if(min_val > val) min_val = val, min_index = i;
    }

    if(min_index > max_index) swap(min_index, max_index); //make the smallest element before the biggest no difference in solution but saves time

    return {min_index, max_index};
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        pii val = min_max(n); int min_index = val.first, max_index = val.second;
        printf("%d\n", min_val(max_index , n - min_index + 1, n - max_index + 1 + min_index)); //left, right, both ways in this order
    }

    return 0;
}