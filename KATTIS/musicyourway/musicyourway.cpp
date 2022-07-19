#include <bits/stdc++.h>
using namespace std;

char atr[1000];
char atrCopy[1000];
char input[35];
int num;
vector <string> curOrder;
vector<vector<string> > arr;
int sortVal;

bool comp(vector<string> x, vector<string> y)
{
    auto xiter = x.begin() + sortVal, yiter = y.begin() + sortVal;
    if(*xiter != *yiter) return *xiter < *yiter;
}

void tokenize()
{
    int i = 0;
    strcpy(atrCopy, atr);
    char *token = strtok(atrCopy, " \n");
    do
    {
        curOrder.insert(curOrder.begin() + i, token);
        token = strtok(0, " \n");
    } while (token && ++i);
}

void output()
{
    printf("%s", atr);
    for(auto &u : arr)
    {
        for(auto &v : u)
            printf(v == *u.begin()? "%s" : " %s", v.c_str());
        printf("\n");
    }
}

int main() 
{
    fgets(atr, 1000, stdin);
    num = 1 + count(atr, atr+strlen(atr), ' ');
    curOrder.resize(num);

    tokenize();

    int count;
    scanf("%d", &count);
    arr.resize(count);

    for(auto &u : arr)
    {
        for(int i=0;i<num;++i)
        {
            scanf("%s", input);
            u.push_back(input);
        }
    }

    int sortCount;
    scanf("%d", &sortCount);

    while (sortCount--)
    {
        scanf("%s", input);
        sortVal = find(curOrder.begin(), curOrder.end(), input) - curOrder.begin();
        stable_sort(arr.begin(), arr.end(), comp);
        output();
        if(sortCount) printf("\n");
    }

    return 0;
}
