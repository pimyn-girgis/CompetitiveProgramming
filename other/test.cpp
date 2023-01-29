/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

int main() {

    set<string> weird;
    char input[100];
    FILE *pi = fopen("file.out", "r");
    FILE *cm = fopen("comp", "r");

    while (fgets(input, sizeof(input), pi)) {
        weird.emplace(input);
    }

    while (fgets(input, sizeof(input), cm)) {
        weird.erase(input);
    }

    printf("%zu\n", weird.size());

    return 0;
}
