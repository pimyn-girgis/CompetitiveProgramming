/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <cstdio>
using namespace std;

char pi[35] = "314159265358979323846264338327";
char input[35];

int main() {
    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%s", input);

        int sum = 0;
        for (int i = 0; input[i] == pi[i] && input[i]; ++i) {
                ++sum;
        }

        printf("%d\n", sum);
    }

    return 0;
}
