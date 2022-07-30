//https://open.kattis.com/problems/integerlists
#include <bits/stdc++.h>
using namespace std;

char cmd[int(1e6 + 5)];

int main() 
{
    int tc, num, val;
    scanf("%d ", &tc);
    list <int> ints;
    while(tc--)
    {
        ints.clear();
        bool error = 0, back = 0;

        scanf("%s %d ", cmd, &num);

        if(!num)
            scanf("[");
        while(num--)
            scanf("%*c%d", &val), ints.push_back(val);
        scanf("] ");

        for(int i = 0;cmd[i]; ++i)
        {
            char c = cmd[i];
            if(c == 'R')
                back = !back;
            else if(c == 'D')
            {
                if(ints.empty())
                {
                    error = 1;
                    break;
                }

                if(back) ints.pop_back();
                else ints.pop_front();
            }
        }

        if(error)
            printf("error\n");
        else
        {
            printf("[");

            if(ints.empty())
                printf("]");

            else if(back)
                while(!ints.empty())
                    printf("%d%c", ints.back(), &ints.back() == &ints.front()? ']' : ','), ints.pop_back();

            else
                while(!ints.empty())
                    printf("%d%c", ints.front(), &ints.front() == &ints.back()? ']' : ','), ints.pop_front();

            printf("\n");
        }
    }
    return 0;
}