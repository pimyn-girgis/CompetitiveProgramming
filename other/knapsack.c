/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <string.h>
#include <stdio.h>
#define max(x, y) (x > y? x : y)

int knapsack(int value[], int weight[], int len, int cap)
{
    int best[len + 1][cap + 1]; //best for each value and each capacity
 
    for(int i = 0; i <= len; ++i) //for every item
         for(int cur_cap = 0; cur_cap <= cap; ++cur_cap) //for every capacity
         {
            int *cur_best = &best[i][cur_cap];
            int *last_best = &best[i - 1][cur_cap]; //best value for the previous capacity

            if(!i || !cur_cap) //if the capacity or the number of items is 0, the best you can do is 0
                *cur_best = 0;
            else if(weight[i - 1] > cur_cap) //If the weight of the current item is greater than the current capacity
                *cur_best = *last_best; //you cannot add it, so you have to use the last best
            else //otherwise, it's the maximum betweeen the last best and the value if you take the current item
                *cur_best = max(*last_best, best[i - 1][cur_cap - weight[i - 1]] + value[i - 1]);
         }
 
    return best[len][cap];
}

int main()
{
    int value[] = {1, 23, 43, 60};
    int weight[] = {3, 1, 10, 12};
    int len = sizeof(weight)/sizeof(int);
    int cap = 12;

    printf("%d\n", knapsack(value, weight, len, cap));

    return 0;
}