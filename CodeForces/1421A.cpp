/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1421/A
* Insight : Let's look at our integers bit by bit; To minimize
            the addition, we want to zero as many bits as pos-
            sible. We have 3 cases:
                1 - both bits are 1
                    make this bit in x = 1.
                2 - both bits are 0
                    make this bit in x = 0.
                3 - one bit is 0 and the other is 1
                    does not make a difference, either case we
                    end up with 1.
            using either "and" or "or" to calculate x would g-
            ive us the desired outcome
**************************************************************
*/

#include <cstdio>

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = a | b;
        printf("%d\n", (a^x) + (b^x));
    }

    return 0;
}