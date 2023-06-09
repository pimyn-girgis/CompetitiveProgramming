/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12192 UVA
* Link    : https://onlinejudge.org/external/121/p12192.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    int height[505][505];

    while(scanf("%d %d\n", &n, &m), n && m) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j){
                scanf("%d%*c", height[i] + j);
            }
        }
        
        int q; scanf("%d\n", &q);
        while(q--) {
            int l, u; scanf("%d %d\n", &l, &u);
        }
        printf("-\n");
    }

    return 0;
}
