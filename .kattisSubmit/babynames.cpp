/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : babynames Kattis
* Link    : https://open.kattis.com/problems/babynames
**************************************************************
* Approach: 
* using a pb_ds, insert gendered names into two different or-
* der statistics trees. Using the tree::lower_bound(), get 
* first and last names with prefixes \in [start, end).
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

ost male;
ost female;

int dif(ost &gender, char *start, char *end)
{
    auto first = gender.lower_bound(start);
    auto last = gender.lower_bound(end);

    int final = last == gender.end()? gender.size() : gender.order_of_key(*last);
    int begin = first == gender.end()? begin = gender.size() : gender.order_of_key(*first);
    
    return final - begin;
}

int main()
{
    int cmd;

    while(scanf("%d", &cmd), cmd)
    {
        char name[35], start[35], end[35];
        int gender;

        switch(cmd)
        {
            case 1:
                scanf("%s %d", name, &gender);

                if(gender == 1) male.insert(name);
                else female.insert(name);

                break;

            case 2:
                scanf("%s", name);

                male.erase(name);
                female.erase(name);

                break;

            case 3:
                scanf("%s %s %d", start, end, &gender);
                int ans;

                if(gender == 1) ans = dif(male, start, end);
                else if(gender == 2) ans = dif(female, start, end);
                else ans = dif(male, start, end) + dif(female, start, end);

                printf("%d\n", ans);
        }
    }

    return 0;
}
