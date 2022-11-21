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

char input[131075];

int min(int x, int y){return x < y? x : y;}

int good_string(int a, int b, char c)
{
    if(a >= b)
        return c != input[b];

    int mid = (a + b) / 2;
}

int solve()
{
    int n;
    scanf("%d %s", &n, input);
    return good_string(0, n - 1, 'a');
}

int main()
{
    int tc;
    scanf("%d\n", &tc);

    while(tc--)
        printf("%d\n", solve());

    return 0;
}