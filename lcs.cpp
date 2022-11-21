#include <stdio.h>
#include <string>
using std::string;
#include <string.h>

int lcs(const string &x, const string &y) //length of Longest Common Substring
{
    int len = 0; //answer
    
    int max_len[x.size() + 1][y.size() + 1]; //array to keep track of already calculated values
    memset(max_len, 0, (x.size() + 1) * (y.size() + 1) * sizeof(int) ); //initialzie to 0
    
    for(int i = (int)x.size() - 1; i >= 0; --i) //calculate from end to finish
        for(int j = (int)y.size() - 1; j >= 0; --j)
            if(x[i] == y[j]) //If the current char is equivalent in both
            {
                max_len[i][j] = max_len[i + 1][j + 1] + 1; //the lcs is 1 + the lcs of the strings without it
                if(len < max_len[i][j]) len = max_len[i][j]; //we want the maximum length
            }
    
    return len;
}

int main()
{
    string x[] = {"STOPP", "Hello", "Pimyn", "Yes", "Geek", "Stop"};
    string y[] = {"claySTOPPclay", "Hell" , "Piman", "Yee", "nerd", "diff"};

    for(int i = 0; i < 5; ++i)
        printf("%d\n", lcs(x[i], y[i]));

    return 0;
}
