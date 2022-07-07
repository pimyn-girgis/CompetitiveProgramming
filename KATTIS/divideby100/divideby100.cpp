#include <bits/stdc++.h>
using namespace std;

char m[1000009];
char n[1000009];

void startingZeros(int val)
{
    int k = val;
    if(k <= 0)
    {
        printf("0.");
        while (k++)
            printf("0");
    }
}

bool trailingZeros(int pos)
{
    for(int i=pos;n[i];++i)
        if(n[i] != '0')
            return 0;
    return 1;
}

int main() 
{
    scanf("%s%s", n, m);
    int val = strlen(n) - strlen(m) + 1;
    startingZeros(val);
    for(int i=0;n[i];++i)
    {  
        if(i >= val && trailingZeros(i))
            break;

        if(i && i == val)
            printf(".");

        printf("%c", n[i]);
    }
    printf("\n");
    return 0;
}
