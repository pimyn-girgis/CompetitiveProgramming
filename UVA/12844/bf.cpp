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
using namespace std;

int w[10];
int w_count[401];
int ans[5];

bool is_valid(int i = 0, int j = 1) {
    if (j == 5) {
        ++i;
        j = i + 1;
    }

    if (i == 4) {
        return true;
    }

    int &val = w_count[ans[i] + ans[j]];

    if (val - 1 < 0) {
        return false;
    }

    --val;
    if (is_valid(i, j + 1)) {
        return true;
    }
    ++val;

    return false;
}

void solve() {
    for (ans[0] = 0; ans[0] <= w[0] / 2; ++ans[0]) {
        ans[1] = w[0] - ans[0];
        for (ans[2] = ans[1]; ans[2] <= w[7] / 2; ++ans[2]) {
            for (ans[3] = ans[2]; ans[3] <= w[9] / 2; ++ans[3]) {
                ans[4] = w[9] - ans[3];
                if (is_valid()) {
                    return;
                }
            }
        }
    }
}



int main() {
    int tc; scanf("%d", &tc);

    for (int test = 1; test <= tc; ++test) {

        for (auto &u : w) {
            scanf("%d", &u);
            ++w_count[u];
        }

        solve();
        sort(ans, ans + 5);

        printf("Case %d:", test);
        for (auto u : ans) {
            printf(" %d", u);
        }
        printf("\n");
    }

    return 0;
}
