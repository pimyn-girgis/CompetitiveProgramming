/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1399/A
* Insight : Notice that if you have any element missing betwe-
            en the smallest and biggest elements, you cannot 
            reduce the array to size 1
            could have sorted in O(log(n)) and compared conse-
            cutive elements especially since input is small b-
            ut I prefer this way
**************************************************************
*/

#include <cstdio>

#define maximize(x, y) if(y > x) x = y //x = max(x, y)
#define minimize(x, y) if(y < x) x = y //x = min(x, y)
#define reset(x) for(auto &u : x) u = 0 //zero values in array x

bool val_exists(bool *arr, bool val, int n) //returns true if an element that compares equal to val exists
{
    while(n--)
        if(*(arr++) == val)
            return true;

    return false;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        bool exist[100];
        int val, n, first = 99, last = 0;
        reset(exist);

        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &val), exist[--val] = true;

            maximize(last, val);
            minimize(first, val);
        }

        printf("%s\n", val_exists(exist + first, 0, last - first + 1)? "NO" : "YES");
    }

    return 0;
}