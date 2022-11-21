/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <stdio.h>
#include <string.h>

char subset_sum(int arr[], int n, int sum)
{
    char dp[n + 1][sum + 1];

    for(int val = 0; val <= n; ++val)
        for(int cur_sum = 0; cur_sum <= sum; ++cur_sum)
        {
            char *cur = &dp[val][cur_sum];
            if(!cur_sum) *cur = 1;
            else if(!val) *cur = 0;
            else
            {
                const int diff = cur_sum - arr[val - 1];
                if(dp[val - 1][cur_sum]) *cur = 1;
                else if(diff >= 0 && dp[val - 1][diff]) *cur = 1;
                else *cur = 0;
            }
        }

    return dp[n][sum];
}

int main()
{
    int arr[] = {3, 5, 6, 7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 15;

    printf("%c\n",  subset_sum(arr, len, sum)? 'y' : 'n');

    return 0;
}