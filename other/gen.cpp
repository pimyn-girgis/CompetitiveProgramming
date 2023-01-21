#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>

const int tc = 150000;
int main() {
    printf("%d\n", tc);

    int arr[10];
    srand(time(0));
    for (int i = 0; i < tc; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[j] = rand() % 300 + 100;
        }

        std::sort(arr, arr + 10);

        for (int j = 0; j < 10; ++j) {
            printf("%d%c", arr[j], j == 10 - 1? '\n' : ' ');
        }
    }

    return 0;
}
