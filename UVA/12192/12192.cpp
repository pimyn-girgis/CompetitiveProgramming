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
using namespace std;

int area[501][501];

int main() {
  int n, m;
  while(scanf("%d%d", &n, &m), n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", area[i] + j);
      }
    }

    int q; scanf("%d", &q);
    while(q--) {
      int l, u; scanf("%d%d", &l, &u);

      int ans = 0;
      for (int i = 0; i < n; ++i) {
        int low = lower_bound(area[i], area[i] + m, l) - area[i];
        int j = 0, k = min(n - i, m - low) - 1;
        while (j <= k) {
          int mid = (j + k) / 2;

          if (area[i + mid][low + mid] <= u) {
            j = mid + 1;
            ans = max(ans, j);
          } else {
            k = mid - 1;
          }
        }
      }

      printf("%d\n", ans);
    }
    printf("-\n");
  }
  return 0;
}
