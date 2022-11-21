/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/
 
#include <cstdio>
#include <algorithm>

void solve(int coin[], int coin_count, int queries)
{
    std::sort(coin, coin + coin_count);

    for(int i = 1; i < coin_count; ++i)
        coin[i] += coin[i - 1];

    while(queries--)
    {
        int coin_per_payment; scanf("%d", &coin_per_payment); ++coin_per_payment;
        bool noceil = !(coin_count % coin_per_payment); //account for ceil function
        printf("%d\n", coin[ (coin_count / coin_per_payment) - noceil ]);
    }
}

int main()
{
    int coin_count, queries;

    scanf("%d", &coin_count);
    int coin[coin_count];

    for(int i = 0; i < coin_count; ++i)
        scanf("%d", coin + i);

    scanf("%d", &queries);
    solve(coin, coin_count, queries);

    return 0;
}
