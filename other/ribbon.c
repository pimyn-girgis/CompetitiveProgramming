/*
**************************************************************
* Authors : Dana AlKhouri & Bemen Girgis
**************************************************************
*/

#include <stdio.h>
#include <string.h>
#define max(x, y) (x > y? x : y)

int max_number_of_pieces(int len[], int value)
{
    int best[value + 1]; //Create array of size value + 1 to keep track of all answers from 0 to value
    memset(best, -1, sizeof(best)); //set all values to -1
    best[0] = 0; //if length is 0, answer is 0

    for(int cur_val = 1; cur_val <= value; ++cur_val) //for every value up to the wanted
        for(int j = 0; j < 3; ++j) //try all possible lengths
        {
            const int diff = cur_val - len[j]; //If your ribbon is longer than the length
            if(diff >= 0 && best[diff] != -1) //and it can be calculated
                best[cur_val] = max(best[cur_val], 1 + best[diff]); //get the maximum
        }

    return best[value];
}

int main()
{
    int len[] = {5, 3, 2};
    int value = 5;

    printf("%d\n", max_number_of_pieces(len, value));

    return 0;
}