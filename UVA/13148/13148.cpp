#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000

int special[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
				 1000000, 1771561, 2985984, 4826809, 7529536, 11390625,
				 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};
int main()
{
	int num;
	int *end = special + sizeof(special)/sizeof(int);
	while (scanf("%d", &num), num)
		printf("%s\n", binary_search(special, end, num)? "Special" : "Ordinary");
	return 0;
}
