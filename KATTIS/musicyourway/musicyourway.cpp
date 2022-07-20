#include <bits/stdc++.h>
using namespace std;

char atr[1000];
char atrCopy[1000];
char input[35];
int num;
vector <string> curOrder;
vector<vector<string> > arr;
int sortVal;

bool comp(vector<string> const &x, vector<string> const &y){return x[sortVal] < y[sortVal];}

void tokenize()
{
    strcpy(atrCopy, atr);
	for(char *token = strtok(atrCopy, " \n");token;token = strtok(0, " \n"))
        curOrder.push_back(token);
}

void output()
{
    printf("%s", atr);
    for(auto &u : arr)
		for(int i = 0; i < u.size(); ++i)
			printf("%s%c", u[i].c_str(), i == u.size() - 1 ? '\n' : ' ');
}

int main() 
{
    fgets(atr, 1000, stdin);
    num = 1 + count(atr, atr+strlen(atr), ' ');

    tokenize();

    int count;
    scanf("%d", &count);
    arr.resize(count);

    for(auto &u : arr)
        for(int i=0;i<num;++i)
            scanf("%s", input), u.push_back(input);

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
