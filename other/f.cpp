/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;
bool cmp(pis &x, pis &y)
{
    if(x.first == y.first)
        return x.second < y.second;

    return x.first > y.first;
}

vector<pis> order;

void solve()
{
    int s;
    string name;
    cin >> name >> s;
    order.push_back(make_pair(s, name));
}

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    sort(order.begin(), order.end(), cmp);

    for(auto &u : order)
        cout << u.second << u.first;

    return 0;
}
