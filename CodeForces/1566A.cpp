/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : https://codeforces.com/problemset/problem/1566/A
* Insight : Since the elements need not be distinct, note that
            you can zero all the elements before the median a-
            nd all the elements from the median to the end ca-
            n all be the same value
**************************************************************
*/

#include <cstdio>

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n, s;
        scanf("%d %d", &n, &s);
        printf("%d\n", s/(n/2 + 1));
    }

    return 0;
}