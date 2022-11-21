/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <stdio.h>

int pair_friends(const int n)
{
    int prev = 1;
    int last = 1;

    for(int i = 2; i <= n; ++i)
    {
        int temp = last + prev * (i - 1);
        prev = last;
        last = temp;
    }

    return n? last : 0;
}

int main()
{
    printf("%d\n", pair_friends(4));

    return 0;
}																								