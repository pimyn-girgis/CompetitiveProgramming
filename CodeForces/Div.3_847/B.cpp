/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, s, r;
vector <int> seq;

bool solve(int t, int sum, int max_val) {

    if (t * max_val + sum < s) {
        return false;
    }

    if (!t) {

        if (sum != s) {
            return false;
        }

        return true;
    }

    for (int i = 1; i <= max_val; ++i) {
        seq.push_back(i);

        if ( solve(t - 1, sum + i, max_val) ) {
            return true;
        }

        seq.pop_back();
    }

    return false;
}

int main() {
    int tc; scanf("%d", &tc);

    while (tc--) {
        seq.clear();
        scanf("%d %d %d", &n, &s, &r);

        seq.push_back(s - r);
        solve(n - 1, s - r, s - r);

        for (int i = 0; i < n; ++i) {
            printf("%d%c", seq[i], i == n - 1? '\n' : ' ');
        }

    }

    return 0;
}
