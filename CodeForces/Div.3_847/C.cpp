/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

int n, missing;
int seq[105][105];
int ans[105];
int cnt[105];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        if (++cnt[seq[i][0]] > 1) {
            ans[0] = seq[i][0];
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (seq[i][0] != ans[0]) {
            memcpy(ans + 1, seq[i], (n - 1) * sizeof(int));
        }
    }

}

int main() {

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                scanf("%d", seq[i] + j);
            }
        }

        solve();

        for (int i = 0; i < n; ++i) {
            printf("%d%c", ans[i], i == n - 1? '\n' : ' ');
        }

    }

    return 0;
}
