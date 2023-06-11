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

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int area[501][501];
int lower[501];
int upper[501];

int main() {
  int n, m;
  while(scanf("%d%d", &n, &m), n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", area[i] + j);
      }
    }

    int q;
    scanf("%d", &q);
    while(q--) {
      int l, u;
      scanf("%d%d", &l, &u);

      for (int i = 0; i < n; ++i) {
        lower[i] = lower_bound(area[i], area[i] + m, l) - area[i];
      }

      int ans = 0;
      for (int i = 0; i < n; ++i) {
        int low = lower[i];
        for (int j = 0; i + j < n && low + j < m; ++j) {
          if (j >= ans && area[i + j][low + j] <= u) {
            ans = j + 1;
          }
        }
      }

      printf("%d\n", ans);
    }
    printf("-\n");
  }
  return 0;
}
