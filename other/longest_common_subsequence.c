/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <stdio.h>
#include <string.h>
#define max(x, y) (x > y? x : y)

int lCSS(const char x[], const char y[])
{
    int row = strlen(x);
    int col = strlen(y);
    int dp[row + 1][col + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= row; ++i)
        for(int j = 1; j <= col; ++j)
            if(x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    return dp[row][col];
}

int main()
{
    printf("%d\n", lCSS("storage", "storm"));

    char x[1000];
    int n = 10;

    return 0;
}