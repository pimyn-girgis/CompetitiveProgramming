/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <climits>

const int min_len = 4;
const int max_len = 10;

char password[max_len + 1] = "hello1";
char guess[max_len + 1];

bool login()
{
    return !strcmp(guess, password);
}

bool crack(int len)
{
    if(!len) return login();

    char &c = guess[len - 1];
    for(c = 0; c < CHAR_MAX; ++c)
        if(crack(len - 1))
            return true;
    
    return false;
}

int main(void)
{
    for(int i = min_len; i <= max_len; ++i)
        if(crack(i))
        {
            printf("%s\n", guess);
            break;
        }

    return 0;
}