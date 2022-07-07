#include <bits/stdc++.h>
using namespace std;

char code[60], guess[60];
bitset<55> done;
bitset<55> Gdone;

int rValue()
{
    int val = 0;
    for(int i=0;code[i];++i)
        if(code[i] == guess[i])
                val += done[i] = Gdone[i] = 1;
    return val;
}

int sValue()
{
    int val = 0;
    for(int i=0;code[i];++i)
    {
        if(!done[i])
            for(int j=0;guess[j];++j)
                if(code[i] == guess[j] && !Gdone[j])
                {
                    val += done[i] = Gdone[j] = 1;
                    break;
                }
    }
    return val;
}

void init(){done.reset();Gdone.reset();}

int main() 
{
    int n;
    init();
    scanf("%d%s%s", &n, code, guess);
    printf("%d %d\n", rValue(), sValue());
    return 0;
}