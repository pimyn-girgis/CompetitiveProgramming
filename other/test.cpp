/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <cstdio>
using namespace std;

int main() {
    int arr[1024] = { 0 };
    arr[0] = 1;
    arr[0] <<= 64;
    for (auto u : arr) {
        printf("%d ", u);
    }

    return 0;
}
